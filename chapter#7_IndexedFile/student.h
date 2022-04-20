#pragma once

#include <iostream>
#include "iobuffer.h"
#include "delim.h"
#include "length.h"
#include "fixfld.h"

using namespace std;

class Student {
public:
	// methods
	Student();
	Student(const Student& student); // copy constructor
	Student& operator = (const Student& student); // assignm operator overloading
	friend istream& operator >> (istream& stream, Student& student);
	friend ostream& operator << (ostream& stream, Student& student);
	void Clear();
	int Unpack(IOBuffer& Buffer);
	int Pack(IOBuffer& Buffer) const;
	char* Key() const; // return key of Student
	void Print(ostream& stream, char* label = 0) const;
	
	static int InitBuffer(DelimFieldBuffer& Buffer);
	static int InitBuffer(LengthFieldBuffer& Buffer);
	static int InitBuffer(FixedFieldBuffer& Buffer);

	// fields
	int Identifier;
	char Name[15];
	char Address[15];
	char DateOfFirstEnrollment[15];
	int NumberOfCreditHourse;
};
