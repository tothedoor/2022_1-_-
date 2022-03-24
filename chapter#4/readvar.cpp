#include <fstream>
#include <strstream>
#include <string.h>
#include "Student.h"
#include <iostream>
using namespace std;
istream & operator >> (istream & stream, Student& student)
{ 
	char delim;
	char identifier[15];
	stream.getline(identifier, 30,'|');
	student.setIdentifier(atoi(identifier));
	if (strlen(identifier)==0) return stream;

	stream.getline(student.Name,30,'|');
	stream.getline(student.Address, 30,'|');
	stream.getline(student.DateOfFirstEnrollment,30,'|');
	
	char numOfCredit[15];
	stream.getline(numOfCredit, 30, '|');
	student.setNumberOfCreditHourse(atoi(numOfCredit));
	return stream;
}
int ReadVariablePerson (istream & stream, Student& student)
{
	short length;
	stream . read ((char*)&length, sizeof(length));
	cout << "length = " << length << endl;
	if (stream . fail()){student.Identifier=0; return 0;}
	char * buffer = new char[length+1];
	stream.read (buffer, length);
	buffer[length] = 0; 
	istrstream strbuff (buffer);
	strbuff >> student;
	return 1;
}
ostream& operator << (ostream& stream, Student& student)
{ 
	cout << "Student 객체를 출력한다" << endl;
	stream << student.Identifier << '|' << student.Name << '|'
		<< student.Address << '|' << student.DateOfFirstEnrollment << '|'
		<< student.NumberOfCreditHourse << '|';
	cout << endl;
	return stream;
}
int main (void){
	char filename [20];
	Student student;
	cout << "Enter the file name:"<<flush;
	cin.getline(filename, 19);
	ifstream stream (filename, ios::in);
	if (stream.fail()) {
		cout << "File open failed!" <<endl;
		return 0;
	}
	while (1) {
		int flag = ReadVariablePerson (stream, student);
		if (flag == 0) break;
		cout << student;
	}
	system("pause");
	return 1;
}
