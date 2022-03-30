#ifndef STUDENT
#define STUDENT

#include <iostream>
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"

class Student
{
public:
	// data members
	int Identifier;
	char Name[15];
	char Address[15];
	char DateOfFirstEnrollment[15];
	int NumberOfCreditHourse;
	// method
	Student();							 // default constructor
	Student &operator=(const Student &); // assign operator
	friend istream& operator >> (istream& stream, Student& student);
	void setIdentifier(int newIdentifier);
	void setName(char newName[]);
	void setAddress(char newAddr[]);
	void setDateOfFirstEnrollment(char newDate[]);
	void setNumberOfCreditHourse(int newValue);

	void addCreditHourse(int value);
	
	// chapter4-2에서 추가된 코드
	void Clear();
	static int InitBuffer(FixedTextBuffer&);
	int Unpack(FixedTextBuffer&);
	int Pack(FixedTextBuffer&) const; // 고정길이레코드
	static int InitBuffer(LengthTextBuffer&);
	int Unpack(LengthTextBuffer&); // 가변길이필드
	int Pack(LengthTextBuffer&) const;
	static int InitBuffer(DelimTextBuffer&);
	int Unpack(DelimTextBuffer&); // 가변길이레코드
	int Pack(DelimTextBuffer&) const;
	void Print(ostream& stream);
};
#endif