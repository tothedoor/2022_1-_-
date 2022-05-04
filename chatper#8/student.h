#pragma once

#include <string.h>
#include <fstream>
#include "iobuffer.h"

class Student {
private:
	int studentId; // 학번
	char name[15]; // 이름
	char address[15];
	char enrollmentDate[15];
	int numOfCredit;

public:
	void addNumofCredit(int addValue);
	int getStudentId();
	int Pack(IOBuffer& buffer) const;
	int Unpack(IOBuffer& buffer);
	ostream& Print(ostream&);
	ostream& PrintHeader(ostream&);
	ostream& PrintNumOfCredit(ostream&);
	Student();
	Student(int id, char* name, char* address, char* enrollmentDate, int numOfCredit);
};