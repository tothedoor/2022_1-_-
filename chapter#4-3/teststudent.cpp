//Student.cc
#include "testStudent.h"

Student::Student() { Clear(); }
Student::Student(Student& student) {
	strcpy(sname, student.sname);
	age = student.age;
	weight = student.weight;
	strcpy(Address, student.Address);
}
void Student::Clear()
{
	// set each field to an empty string
	// Q: 완성해야 함
	// A: 모든 필드들을 초기화
	sname[0] = 0;
	age = 0;
	weight = 0.0;
	Address[0] = 0;
}

int Student::Pack(IOBuffer & Buffer) const
{// pack the fields into a FixedFieldBuffer, 
 // return TRUE if all succeed, FALSE o/w
	int numBytes;
	Buffer.Clear();
	// Q: 완성해야 함
	
	// 작성 코드 시작
	numBytes = Buffer.Pack(sname);
	if (numBytes == -1) return FALSE;

	char age_char[10];
	snprintf(age_char, 10, "%d", age);
	numBytes = Buffer.Pack(age_char);
	if (numBytes == -1) return FALSE;

	char weight_char[10];
	snprintf(weight_char, 10, "%f", weight);
	numBytes = Buffer.Pack(weight_char);
	if (numBytes == -1) return FALSE;

	numBytes = Buffer.Pack(Address);
	if (numBytes == -1) return FALSE;
	// 작성한 코드 끝

	return TRUE;
}

int Student::Unpack(IOBuffer & Buffer)
{
	Clear();
	int numBytes;
	
	// 작성 코드 시작
	numBytes = Buffer.Unpack(sname);
	if (numBytes == -1) return FALSE;

	char age_char[10];
	numBytes = Buffer.Unpack(age_char);
	if (numBytes == -1) return FALSE;
	age = atoi(age_char);
	
	char weight_char[20];
	numBytes = Buffer.Unpack(weight_char);
	if (numBytes == -1) return FALSE;
	weight = atof(weight_char);

	numBytes = Buffer.Unpack(Address);
	if (numBytes == -1) return FALSE;
	// 작성 코드 시작

	return TRUE;
}


void Student::Print(ostream & stream, char* label) const
{
	//수정 필요
	if (label == 0) stream << "Student:";
	else stream << label;
	stream << "\n\t   name: " << sname;
	stream << "\n\t    age: " << age;
	stream << "\n\t weight: " << weight;
	stream << "\n\tAddress: " << Address << "\n";
}

istream& operator>>(istream & stream, Student & student)
{	
	cout << "Enter name: " << flush;
	stream.getline(student.sname, 41);
	
	cout << "Enter age: " << flush;
	char age[10];
	stream.getline(age, 11);
	student.age = atoi(age);

	cout << "Enter weight: " << flush;
	char weight[10];
	stream.getline(weight, 11);
	student.weight = atof(weight);
	
	cout << "Enter address: " << flush;
	stream.getline(student.Address, 41);

	return stream;
}

ostream& operator<<(ostream& stream, Student& student)
{
	stream << "Student's Info: ";
	stream << "\n\t   name: " << student.sname
		   << "\n\t    age: " << student.age
		   << "\n\t weight: " << student.weight
		   << "\n\tAddress: " << student.Address << "\n\n";
	return stream;
}