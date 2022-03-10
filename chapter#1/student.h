#pragma once
#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <stdlib.h>

using namespace std;

class Student
{
public:
	// data members
	int Identifier;
	char Name[11];
	char Address[16];
	char DateOfFirstEnrollment[8];
	int NumberOfCreditHourse;
	// method
	Student();							 // default constructor
	Student &operator=(const Student &); // assign operator

	void setIdentifier(int newIdentifier);
	void setName(char newName[]);
	void setAddress(char newAddr);
	void setDateOfFirstEnrollment(char newDate[]);
	void setNumberOfCreditHourse(int newValue);

	void addCreditHourse(int value);
};

/*
Student::Student()
{//constructor

	LastName[0] = 0; FirstName[0] = 0; Address[0] = 0;
	City[0] = 0; State[0] = 0; ZipCode[0] = 0;
}
*/

#endif