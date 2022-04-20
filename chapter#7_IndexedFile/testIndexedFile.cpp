//testind.cc - TextindexedFile 사용 실습
#include "textind.h"
#include "delim.h"
#include "buffile.h"
#include "recordng.h"
#include "indfile.h"
#include <iostream>
#include "student.h"

int main (void)
{// first argument is the file name for the data file
	int result;

	TextIndex RecIndex (10);
	DelimFieldBuffer Buffer; // create a buffer
	TextIndexedFile<Student> IndFile (Buffer, 12, 10);
	char fileName[20];
	//TextIndexedFile<RecType>::TextIndexedFile(IOBuffer & buffer, int keySize, int maxKeys)
	cout << "Enter the file name:" << flush;
	cin.getline(fileName, 19);
	result = IndFile . Create (fileName, ios::out);
	if (!result) 
	{
		cout<<"Unable to open indfile "<< result << endl;
		return 0;
	}	
	int recaddr;
	//write records
	//Recording* R[20], foundRecord;
	int count;
	cout << "Enter number of Student: ";
	cin >> count;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	Student *student = new Student[count];
	
	
	/*
	R[0] = new Recording("LON", "2312", "Romeo and Juliet", "Prokofiev", "Maazel");
	R[1] = new Recording("RCA", "2626", "Quartet in C Sharp Minor", "Beethoven", "Julliard");
	R[2] = new Recording("WAR", "23699", "Touchstone", "Corea", "Corea");
	R[3] = new Recording("ANG", "3795", "Symphony No. 9", "Beethoven", "Giulini");
	R[4] = new Recording("COL", "38358", "Nebraska", "Springsteen", "Springsteen");
	R[5] = new Recording("DG", "18807", "Symphony No. 9", "Beethoven", "Karajan");
	R[6] = new Recording("MER", "75016", "Coq d'or Suite", "Rimsky-Korsakov", "Leinsdorf");
	R[7] = new Recording("COL", "31809", "Symphony No. 9", "Dvorak", "Bernstein");
	R[8] = new Recording("DG", "139201", "Violin Concerto", "Beethoven", "Ferras");
	R[9] = new Recording("FF", "245", "Good News", "Sweet Honey in the Rock", "Sweet Honey in the Rock");
	*/

	for (int i = 0; i < count; i++)
	{
		cin >> student[i];
		recaddr = IndFile.Append(student[i]);
		cout << "IndFile student[" << i << "] at recaddr " << recaddr << endl;
	}
	IndFile.Close();


	cout << "\n--------------------------------------------------\n" << "Read \"" << fileName << "\"\n";
	Student readedStudent;
	result = IndFile.Open(fileName, ios::in);
	if (result < 0) {
		cout << "Unable to read IndFile " << result << endl;
		return -1;
	}
	for (int i = 0; i < count; i++) {
		IndFile.Read(readedStudent);
		cout << readedStudent << endl;
	}
	IndFile.Close();

	cout << "\n--------------------------------------------------\n" 
		 << "<Search Student by key>" << endl;
	Student foundRecord;
	char searchKey[10];
	int option;
	result = IndFile.Open(fileName, ios::in);
	if (result < 0) {
		cout << "Unable to read IndFile " << result << endl;
		return -1;
	}

	while (1) {
		cout << "Enter key of student you want(student's ID):";
		cin.getline(searchKey, 9);
		cin.clear();
		result = IndFile.Read(searchKey, foundRecord);
		if (result < 0) {
			cout << "key:" << searchKey << " does not existed!" << endl;
		}
		else {
			cout << "key:" << searchKey << " existed!" << endl;
			foundRecord.Print(cout);
		}
		cout << "enter 1 if you want to exit. Enter any input to continue: " << flush;
		cin >> option;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		if (option == 1)
			break;
	}
		
	IndFile.Close();
	
	system("pause");
	return 1;
}

