#include <fstream>
#include <string.h>
#include "coseq.h"

// strlist.cpp
#include "strlist.h"

const char * StringListProcess::LowValue = "";
const char * StringListProcess::HighValue = "\xff";

StringListProcess::StringListProcess (int numberOfLists)
: CosequentialProcess<String&>(numberOfLists), OutputList()
{
	Lists = new ifstream[NumberOfLists+1];
	Items = new String[NumberOfLists+1];
}

int StringListProcess::InitializeList (int ListNumber, char * ListName)
{
	Lists[ListNumber] . open(ListName);
	Items[ListNumber] = LowValue;
	return 1;
}

int StringListProcess::InitializeOutput (char * OutputListName)
{	
	OutputList.open(OutputListName);
	return 1;
}

/*
* ListNumber에 해당하는 list에 읽을 다음 record가 있는지 확인하고
* 있는 경우 empty string이 아닌지, 순서에 알맞은 record인지 확인하고
* List[ListNumber]에 읽은 item을 저장하는 함수.
* 성공하는 경우 1을, 아닌 경우 0을 return한다.
*/
int StringListProcess::NextItemInList (int ListNumber)
//get next item from this list
{
	char ThisItem[MaxItemLength];
	String PreviousItem = Items[ListNumber];
	Lists[ListNumber].getline(ThisItem, MaxItemLength+1); // get line from file
	// test for errors and termination
	if (!Lists[ListNumber].good()) // end of file. 더 이상 읽을 record가 없는 경우
	{	
		Items[ListNumber] = HighValue;
		return 0;}
	if (strlen(ThisItem)==0) // 읽었으나 empty string인 경우
	{	
		Items[ListNumber] = LowValue;
		return 0;}
	if (strcmp(ThisItem, (char*)PreviousItem) < 0) // 현재 값이 이전 값보다 큰 경우 -> 순서가 잘 못된 경우임
	{
		cerr << "Items out of order: current "<<ThisItem
			<< " previous "<<(char*)PreviousItem<<endl;
		Items[ListNumber] = HighValue; return 0;
	}
	// this is a new item, store it
	Items[ListNumber]=ThisItem;//store this Item as current item
	cout << "list = " << ListNumber << "\t::" << Items[ListNumber] << endl;//추가한 코드
	return 1;
}

// ListNumber에 해당하는 List에서 Item을 return 해주는 함수
String& StringListProcess::Item (int ListNumber)
// return current item from this list
{	return Items[ListNumber];}

/*
* ListNumber에 해당하는 List의 현재 Item을 OutputList에 add 하는 함수
*/
int StringListProcess::ProcessItem (int ListNumber)
// process the item in this list
// output a line containing the item
{	
	OutputList << Items[ListNumber] <<endl;
	return 1;
}

// 열려있는 file들(List file들, OutputList file)을 close해주는 함수
int StringListProcess::FinishUp()
{
	for (int i = 1; i <= NumberOfLists; i++)
		Lists[i].close();
	OutputList.close();
	return 1;
}
