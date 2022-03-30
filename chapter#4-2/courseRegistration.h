#ifndef COURSEREGISTRATION
#define COURSEREGISTRATION

#include <iostream>
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"

class CourseRegistration {
public:
	// data member��
	int courseId;
	int studentId;
	int NumberOfCreditHourse;
	char grade[5];

	CourseRegistration();
	CourseRegistration& operator = (const CourseRegistration& cr);
	friend istream& operator >> (istream& stream, CourseRegistration& cr);

	void setCourseId(int courseId);
	void setStudentId(int studentId);
	void setNumberOfCreditHourse(int numOfCredit);
	void setGrade(char grade[]);

	// chapter4-2���� �߰��� �ڵ�
	void Clear();
	static int InitBuffer(FixedTextBuffer&);
	int Unpack(FixedTextBuffer&);
	int Pack(FixedTextBuffer&) const; // �������̷��ڵ�
	static int InitBuffer(LengthTextBuffer&);
	int Unpack(LengthTextBuffer&); // ���������ʵ�
	int Pack(LengthTextBuffer&) const;
	static int InitBuffer(DelimTextBuffer&);
	int Unpack(DelimTextBuffer&); // �������̷��ڵ�
	int Pack(DelimTextBuffer&) const;
	void Print(ostream& stream);
};
#endif // ! COURSEREGISTRATION
