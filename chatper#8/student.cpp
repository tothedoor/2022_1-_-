#include "student.h"
#include <iomanip>
#include <string.h>

int Student::getStudentId() {
	return studentId;
}

void Student::addNumofCredit(int addValue) {
	this->numOfCredit += addValue;
}
int Student::Pack(IOBuffer& buffer) const {
	buffer.Clear();
	buffer.Pack(&studentId, sizeof(studentId));
	buffer.Pack(&name, -1);
	buffer.Pack(&address, -1);
	buffer.Pack(&enrollmentDate, -1);
	buffer.Pack(&numOfCredit, sizeof(numOfCredit));
	return 1;
}

int Student::Unpack(IOBuffer& buffer) {
	buffer.Unpack(&studentId, sizeof(studentId));
	buffer.Unpack(&name, -1);
	buffer.Unpack(&address, -1);
	buffer.Unpack(&enrollmentDate, -1);
	buffer.Unpack(&numOfCredit, sizeof(numOfCredit));

	return 1;
}

Student::Student() {
	studentId = 0;
	name[0] = 0;
	address[0] = 0;
	enrollmentDate[0] = 0;
	numOfCredit = 0;
}

Student::Student(int id, char* name, char* address, char* enrollmentDate, int numOfCredit) {
	this->studentId = id;
	strcpy(this->name, name);
	strcpy(this->address, address);
	strcpy(this->enrollmentDate, enrollmentDate);
	this->numOfCredit = numOfCredit;
}

ostream& Student::Print(ostream& stream) {
	stream.setf(ios::right, ios::adjustfield);
	stream << studentId << '\t';
	stream.setf(ios::left, ios::adjustfield);
	stream << setw(20) << name;
	stream.setf(ios::left, ios::adjustfield);
	stream << setw(20) << address;
	stream.setf(ios::left, ios::adjustfield);
	stream << setw(20) << enrollmentDate;
	stream.setf(ios::left, ios::adjustfield);
	stream << setw(5) << numOfCredit << endl;
	return stream;
}

ostream& Student::PrintHeader(ostream& stream) {
	stream << studentId << "\t" << name << endl;
	return stream;
}

ostream& Student::PrintNumOfCredit(ostream& stream) {
	stream << "\t\t\t\tTotal Credit: "
		<< setw(8) << numOfCredit << endl;
	return stream;
}
