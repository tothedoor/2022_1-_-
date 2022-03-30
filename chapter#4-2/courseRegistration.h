#ifndef COURSEREGISTRATION
#define COURSEREGISTRATION

#include <iostream>
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"

class CourseRegistration {
public:
	// data member들
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
#endif // ! COURSEREGISTRATION
