#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "Student.h"
using namespace std;
const int MaxBufferSize = 200;
int WritePerson (ostream & stream, Student& student)
{	char buffer [MaxBufferSize];

	string identifier = to_string(student.Identifier);
	strcpy(buffer, identifier.c_str()); strcat(buffer,"|");
	strcat(buffer, student.Name); strcat(buffer,"|");
	strcat(buffer, student.Address);  strcat(buffer,"|");
	strcat(buffer, student.DateOfFirstEnrollment);  strcat(buffer, "|");
	string numOfCredit = to_string(student.NumberOfCreditHourse);
	strcat(buffer, numOfCredit.c_str());  strcat(buffer, "|");
	short length = strlen(buffer);
	stream.write ((char *)&length, sizeof(length)); // write length
	stream.write (&buffer[0], length);
	return 1;
}
istream& operator >> (istream& stream, Student& Student)
{
	cout << "Enter Identifier or <cr>: " << flush;
	char identifier[10];
	stream.getline(identifier, 30);
	Student.setIdentifier(atoi(identifier));
	if (strlen(identifier) == 0) return stream;

	cout << "Enter Name: " << flush; stream.getline(Student.Name, 30);
	cout << "Enter address: " << flush; stream.getline(Student.Address, 30);
	cout << "Enter Date of First Enrollment: " << flush; stream.getline(Student.DateOfFirstEnrollment, 32);
	cout << "Enter Number Of Credit hourse: " << flush;
	char numOfCredit[15];
	stream.getline(numOfCredit, 30);
	Student.setNumberOfCreditHourse(atoi(numOfCredit));
	return stream;
}
int main (void){
	char filename [20];
	Student student;
	cout << "Enter the file name:"<<flush;
	cin.getline(filename, 19);
	ofstream stream (filename, ios::out);
	if (stream.fail()) {
		cout << "File open failed!" <<endl;
		return 0;
	}
	while (1) {
		cin >> student;
		if (student.Identifier == 0) break;
		WritePerson(stream,student);
	}
	system("pause");
	return 1;
}

