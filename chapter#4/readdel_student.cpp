#include <fstream>
#include <string.h>
#include <iostream>
#include "student.h"

using namespace std;
istream & operator >> (istream & stream, Student & p)
{
	char delim;
	char identifier[10];
	stream.getline(identifier, 30,'|');
	p.setIdentifier(atoi(identifier));
	if (strlen(identifier)==0) return stream; 
	stream.getline(p.Name,30,'|');
	stream.getline(p.Address,30,'|');
	stream.getline(p.DateOfFirstEnrollment, 30,'|');
	char numOfCredit[15];
	stream.getline(numOfCredit,30,'|');
	p.setNumberOfCreditHourse(atoi(numOfCredit));

	cout << endl<<"istream.getline(object, size, '|') ½ÇÇàµÊ" << endl;
	return stream;
}
ostream& operator << (ostream& stream, Student& p)
{ // insert fields into file
	cout << "Student °´Ã¼¸¦ Ãâ·ÂÇÑ´Ù" << endl;
	stream << p.Identifier << '|' << p.Name << '|'
		<< p.Address << '|' << p.DateOfFirstEnrollment << '|'
	    << p.NumberOfCreditHourse << '|';
	cout << endl;
	return stream;
}
int main (void){
	char filename [20];
	Student p;
	cout << "Enter the file name:"<<flush;
	cin.getline(filename, 19);
	ifstream file (filename, ios::in);
	if (file.fail()) {
		cout << "File open failed!" <<endl;
		return 0;
	}
	while (1) {
		file >> p;
		if (p.Identifier == 0) break;
		cout << p;
	}
	system("pause");
	return 1;
}
