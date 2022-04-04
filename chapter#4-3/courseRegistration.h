#pragma once

#ifndef COURSEREGISTRATION
#define COURSEREGISTRATION

#include <iostream>
#include "iobuffer.h"

class CourseRegistration {
public:
	// fields
	int courseId;
	int studentId;
	int NumberOfCreditHourse;
	char grade[5];

	// operations
	CourseRegistration();
	CourseRegistration(CourseRegistration&);
	void Clear();
	int Unpack(IOBuffer&);
	int Pack(IOBuffer&) const;
	void Print(ostream&, char* label = 0) const;
	friend istream& operator>>(istream& stream, CourseRegistration& course);
	friend ostream& operator<<(ostream& stream, CourseRegistration& course);
};

#endif