#include "student.h"
#include <strstream>
#include <string.h>
#include <string>

Student::Student() {
	Identifier = 0;
	Name[0] = 0;
	Address[0] = 0;
	DateOfFirstEnrollment[0] = 0;
	NumberOfCreditHourse = 0;
}

Student::Student(const Student& student) {
	Identifier = student.Identifier;
	strcpy_s(Name, student.Name);
	strcpy_s(Address, student.Address);
	strcpy_s(DateOfFirstEnrollment, student.DateOfFirstEnrollment);
	NumberOfCreditHourse = student.NumberOfCreditHourse;
}

Student& Student::operator = (const Student& student) {
	Identifier = student.Identifier;
	strcpy_s(Name, student.Name);
	strcpy_s(Address, student.Address);
	strcpy_s(DateOfFirstEnrollment, student.DateOfFirstEnrollment);
	NumberOfCreditHourse = student.NumberOfCreditHourse;

	return *this;
}

void Student::Clear() {
	Identifier = 0;
	Name[0] = 0;
	Address[0] = 0;
	DateOfFirstEnrollment[0] = 0;
	NumberOfCreditHourse = 0;
}

int Student::Unpack(IOBuffer& Buffer) {
	int numBytes;

	char id_char[10];
	numBytes = Buffer.Unpack(id_char);
	if (numBytes == -1) { return FALSE; } // fail
	Identifier = atoi(id_char);

	numBytes = Buffer.Unpack(Name);
	if (numBytes == -1) { return FALSE; } // fail
	numBytes = Buffer.Unpack(Address);
	if (numBytes == -1) { return FALSE; } // fail
	numBytes = Buffer.Unpack(DateOfFirstEnrollment);
	if (numBytes == -1) { return FALSE; } // fail

	char numOfCredit_char[15];
	numBytes = Buffer.Unpack(numOfCredit_char);
	if (numBytes == -1) { return FALSE; } // fail
	NumberOfCreditHourse = atoi(numOfCredit_char);

	return TRUE; // success
}

int Student::Pack(IOBuffer& Buffer) const{
	int numBytes;

	char id_char[10];
	snprintf(id_char, 10, "%d", Identifier);
	numBytes = Buffer.Pack(id_char);
	if (numBytes == -1) { return FALSE; } // fail

	numBytes = Buffer.Pack(Name);
	if (numBytes == -1) { return FALSE; } // fail
	numBytes = Buffer.Pack(Address);
	if (numBytes == -1) { return FALSE; } // fail
	numBytes = Buffer.Pack(DateOfFirstEnrollment);
	if (numBytes == -1) { return FALSE; } // fail

	char numOfCredit_char[10];
	snprintf(numOfCredit_char, 10, "%d", NumberOfCreditHourse);
	numBytes = Buffer.Pack(numOfCredit_char);
	if (numBytes == -1) { return FALSE; } // fail

	return TRUE; // success
}

char* Student::Key() const {
	ostrstream key;
	key << Identifier << ends;
	return key.str();
}

void Student::Print(ostream& stream, char* label) const {
	if (label == 0) { stream << "Student's Informations: "; }
	else { stream << label; }
	stream << "\n\t           Identifier: " << Identifier;
	stream << "\n\t                 Name: " << Name;
	stream << "\n\t              Address: " << Address;
	stream << "\n\tDateOfFirstEnrollment: " << DateOfFirstEnrollment;
	stream << "\n\t NumberOfCreditHourse: " << NumberOfCreditHourse << "\n";
}

int Student::InitBuffer(FixedFieldBuffer& Buffer) {
	int result;
	result = Buffer.AddField(10); // int Identifier
	result = result && Buffer.AddField(15); // Name[15]
	result = result && Buffer.AddField(15); // Address[15]
	result = result && Buffer.AddField(15); // DateOfFirstEnrollment[15]
	result = Buffer.AddField(10); // int NumberOfCreditHourse
	return result;
}

int Student::InitBuffer(LengthFieldBuffer& Buffer) {
	return TRUE;
}

int Student::InitBuffer(DelimFieldBuffer& Buffer) {
	return TRUE;
}

istream& operator >> (istream& stream, Student& student) {
	cout << "Enter ID: " << flush;
	char id[10];
	stream.getline(id, 11);
	student.Identifier = atoi(id);

	cout << "Enter Name: " << flush;
	stream.getline(student.Name, 16);
	cout << "Enter Address: " << flush;
	stream.getline(student.Address, 16);
	cout << "Enter DateOfFirstEnrollment: " << flush;
	stream.getline(student.DateOfFirstEnrollment, 16);

	cout << "Enter NumberOfCreditHourse: " << flush;
	char numOfCredit[10];
	stream.getline(numOfCredit, 11);
	student.NumberOfCreditHourse = atoi(numOfCredit);

	return stream;
}

ostream& operator << (ostream& stream, Student& student) {
	student.Print(stream);
	return stream;
}