#pragma once
#include <string.h>
#include <fstream>
#include "iobuffer.h"

class CourseRegistration {
private:
	int courseId;
	int studentId;
	int credit;
	char grade[5];
public:
	int getCredit();
	int getStudentId();
	int getCourseId();
	int Pack(IOBuffer& buffer) const;
	int Unpack(IOBuffer& buffer);
	//ostream& Print(ostream&);
	ostream& PrintLine(ostream&);
	CourseRegistration();
	CourseRegistration(int courseId, int studentId, int credit, char* grade);
};