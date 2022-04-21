#include "recfile.h"
#include "tindbuff.h"
#include <strstream>
#include <string.h>
// template class to support direct read and write of records
// The template parameter RecType must support the following
//	int Pack (BufferType &); pack record into buffer
//	int Unpack (BufferType &); unpack record from buffer

/*
* 사용자 정의 record를 file에 저장할 때 index와 record 자체를 동시에 저장할 수
* 있도록 해주는 Class이다.
*/
template <class RecType>
class TextIndexedFile
{public:
	int Read (RecType & record); // read next record
	int Read (char * key, RecType & record); // read by key
	int Append (const RecType & record);
	//int Delete(const RecType & record);//No found in the appendix
	int Update (char * oldKey, const RecType & record);
	int Create (char * name, int mode=ios::in|ios::out);
	int Open (char * name, int mode=ios::in|ios::out);
	int Close ();
	TextIndexedFile (IOBuffer & buffer, 
		int keySize, int maxKeys = 100); 
	~TextIndexedFile (); // close and delete
protected:
	TextIndex Index; // record들의 key, recordAddress를 저장하는 table (즉 index table이다.)
	BufferFile IndexFile; // TextIndex가 저장되는 file. 사용자 정의 record가 아니므로 BufferFile을 이용함
	TextIndexBuffer IndexBuffer; // TextIndex를 IndexFile(BufferFile)에 저장할 때 사용하는 Buffer이다.(FixedLengthBuffer 이다.)
	RecordFile<RecType> DataFile; // 실제 record가 저장되는 file이다. 사용자 정의 record가 저장되므로 RecordFile을 사용한다.
	char * FileName; // base file name for file
	int SetFileName(char * fileName, // .dat, .ind file의 이름을 각 확장자에 맞게 설정하는 함수
		char *& dataFileName, char *& indexFileName);
};

// template method bodies

// parameter로 전달된 사용자 정의 record에 DataFile에서 순차적으로 읽어오는 함수
template <class RecType>
int TextIndexedFile<RecType>::Read (RecType & record)
{	return DataFile . Read (record, -1);}

// parameter로 전달된 key에 해당하는 record를 Read하는 함수
template <class RecType>
int TextIndexedFile<RecType>::Read (char * key, RecType & record)
{
	int ref = Index.Search(key); // key에 해당하는 record의 위치를 Index Table로부터 읽어옴
	if (ref < 0) return -1; // 존재하지 않는 key 라면 fail return
	int result = DataFile . Read (record, ref); // 존재한다면 DataFile에서 읽어온 address에 있는 record를 read
	return result;
}

/*
* 인자로 전달받은 사용자 정의 record를 file에 추가하는 함수
* - RecordFile dataFile와 BufferFile IndexFile에 모두 추가된다.
*/
template <class RecType>
int TextIndexedFile<RecType>::Append (const RecType & record)
{
	char * key = record.Key();
	int ref = Index.Search(key);
	if (ref != -1) // key already in file
		return -1;
	ref = DataFile . Append(record);
	int result = Index . Insert (key, ref);
	return ref;
}

/*
* 인자로 전달받은 key에 해당하는 record를 찾고 그 record를인자로 전달받은 
* record로 변경하는 함수.
* - 구현되어 있지는 않음. 추후에 구현하며 연습해보기
*/
template <class RecType>
int TextIndexedFile<RecType>::Update 
	(char * oldKey, const RecType & record)
// Update is left as an exercise. 
//	It requires BufferFile::Update, and BufferFile::Delete
{	return -1;}

// .dat, .ind 확장자명을 추가하여 각 file의 이름을 설정하는 함수
template <class RecType>
int TextIndexedFile<RecType>::SetFileName(char * fileName,
	char *& dataFileName, char *& indexFileName)
// generate names for the data file and the index file
{
	if (FileName != 0) // object is already attached to a file
		return 0;
	// set FileName member
	FileName = strdup(fileName);
	// generate real file names
	ostrstream dataName, indexName;
	dataName << FileName <<".dat"<<ends;
	indexName<< FileName<<".ind"<<ends;
	dataFileName = strdup(dataName . str());
	indexFileName = strdup(indexName . str());
	return 1;
}

/*
* 원하는 file이름과 mode로 file을 생성하는 함수.
* data file와 index file 두 개를 생성한다.
*/
template <class RecType>
int TextIndexedFile<RecType>::Create (char * fileName, int mode)
// use fileName.dat and fileName.ind
{
	int result;
	char * dataFileName, * indexFileName;
	result = SetFileName (fileName, dataFileName, indexFileName);
cout <<"file names "<<dataFileName<<" "<<indexFileName<<endl;
	if (result == -1) return 0;
	result = DataFile.Create (dataFileName, mode);
	if (!result)
	{
		FileName = 0; // remove connection
		return 0;
	}
	result = IndexFile.Create (indexFileName, ios::out|ios::in);
	if (!result)
	{
		DataFile . Close(); // close the data file
		FileName = 0; // remove connection
		return 0;
	}
	return 1;
}

/*
* file을 여는 함수
*/
template <class RecType>
int TextIndexedFile<RecType>::Open (char * fileName, int mode)
// open data and index file and read index file
{
	int result;
	char * dataFileName, * indexFileName;
	result = SetFileName (fileName, dataFileName, indexFileName);
	if (!result) return 0;
	// open files
	result = DataFile.Open (dataFileName, mode);
	if (!result)
	{
		FileName = 0; // remove connection
		return 0;
	}
	result = IndexFile.Open (indexFileName, ios::out);
	if (!result)
	{
		DataFile . Close(); // close the data file
		FileName = 0; // remove connection
		return 0;
	}
	// read index into memory
	result = IndexFile . Read ();
	if (result != -1)
	{
		result = IndexBuffer . Unpack (Index);
		if (result != -1) return 1;
	}
	// read or unpack failed!
	DataFile.Close();
	IndexFile.Close();
	FileName = 0;
	return 0;
}

/*
* open 했던 file들을 닫는 함수
*/
template <class RecType>
int TextIndexedFile<RecType>::Close ()
{	int result;
	if (!FileName) return 0; // already closed!
	DataFile . Close();
	IndexFile . Rewind();
	IndexBuffer.Pack (Index);
	result = IndexFile . Write ();
	cout <<"result of index write: "<<result<<endl;
	IndexFile . Close ();
	FileName = 0;
	return 1;
}


// Contstructer
template <class RecType>
TextIndexedFile<RecType>::TextIndexedFile (IOBuffer & buffer,
		int keySize, int maxKeys)
	:DataFile(buffer), Index (maxKeys), 
	IndexFile(IndexBuffer), IndexBuffer(keySize, maxKeys)
{
	FileName = 0;
}

// Destructer
template <class RecType>
TextIndexedFile<RecType>::~TextIndexedFile ()
{	Close(); }

