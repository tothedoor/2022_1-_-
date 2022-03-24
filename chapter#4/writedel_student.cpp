#include <fstream>
#include "student.h"
#include <iostream>

using namespace std;
ostream & operator << (ostream & stream, Student& p)
{
	stream << p.Identifier <<'|'<< p.Name <<'|' << p.Address << '|' 
		   << p.DateOfFirstEnrollment << '|'<< p.NumberOfCreditHourse << '|';
	return stream;
}
istream& operator >> (istream& stream, Student& p)
{ 
	cout << "Enter Identifier: " << flush;
	char identifier[10];
	stream.getline(identifier, 10);
	p.setIdentifier(atoi(identifier)); // 읽어드린 값을 정수로 변환하여 identifier로 set
	cout << "Enter Name: " << flush; stream.getline(p.Name, 30);
	cout << "Enter address: " << flush; stream.getline(p.Address, 30);
	cout << "Enter Date of First Enrollment: " << flush; stream.getline(p.DateOfFirstEnrollment, 20);
	cout << "Enter Number Of Credit hourse: " << flush;
	char numOfCredit[15]; 
	stream.getline(numOfCredit, 30);
	p.setNumberOfCreditHourse(atoi(numOfCredit)); // 읽은 값 정수변환 후 Student p의 field로 설정
	return stream;
}
int main (void) {
	char filename [20];
	Student p;
	cout << "Enter the file name:"<<flush;
	cin.getline(filename, 19);
	ofstream file (filename, ios::out);
	if (file.fail()) {
		cout << "File open failed!" <<endl;
		return 0;
	}
	while (1) {
		cin >> p;
		// write person to file
		file << p;

		cout << "Enter 'y' to exit. Other inputs are in progress.";
		char operation;
		cin >> operation;
		if (operation == 'y') break; // exit
	}

	system("pause");

	return 0;
}
