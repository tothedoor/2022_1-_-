#include "courseRegistration.h""
#include <iostream>
#include <string.h>
using namespace std;
CourseRegistration::CourseRegistration() {
	courseId = 0;
	studentId = 0;
	NumberOfCreditHourse = 0;
}

CourseRegistration& CourseRegistration::operator = (const CourseRegistration& cr) {
	this->courseId = cr.courseId;
	this->studentId = cr.studentId;
	this->NumberOfCreditHourse = cr.NumberOfCreditHourse;
	strcpy(this->grade, cr.grade);

	cout << "assign::operator =  is called." << endl;
	return *this;
}

istream& operator >> (istream& stream, CourseRegistration& cr) {
	cout << "-------------------------------------------------------\n" << flush;
	cout << "Enter courseId: " << flush;
	char courseId[5];
	stream.getline(courseId, 10);
	cr.courseId = atoi(courseId);
	cout << "Enter studentId: " << flush;
	char studentId[5];
	stream.getline(studentId, 10);
	cr.studentId = atoi(studentId);
	cout << "Enter Number Of CreditHourse: " << flush;
	char numOfCredit[5];
	stream.getline(numOfCredit, 10);
	cr.NumberOfCreditHourse = atoi(numOfCredit);
	cout << "Enter grade: " << flush;
	stream.getline(cr.grade, 30);
	return stream;
}

void CourseRegistration::setCourseId(int courseId) { this->courseId = courseId; }
void CourseRegistration::setStudentId(int studentId) { this->studentId = studentId; }
void CourseRegistration::setNumberOfCreditHourse(int numOfCredit) { this->NumberOfCreditHourse = numOfCredit; }
void CourseRegistration::setGrade(char grade[]) { strcpy(this->grade, grade); }

// chapter 4-2 에서 추가된 코드
void CourseRegistration::Clear() {
	courseId = 0;
	studentId = 0;
	NumberOfCreditHourse = 0;
	grade[0] = 0;
}

int CourseRegistration::Pack(FixedTextBuffer& Buffer) const {
	int result;
	Buffer.Clear();
	result = Buffer.Pack((char*)&courseId);
	result = result && Buffer.Pack((char*)&studentId);
	result = result && Buffer.Pack((char*)&NumberOfCreditHourse);
	result = result && Buffer.Pack(this->grade);
	return result;
}

int CourseRegistration::Unpack(FixedTextBuffer& Buffer) {
	Clear();
	int result;
	result = Buffer.Unpack((char*)&courseId);
	result = result && Buffer.Unpack((char*)&studentId);
	result = result && Buffer.Unpack((char*)&NumberOfCreditHourse);
	result = result && Buffer.Unpack(this->grade);
	return result;
}

int CourseRegistration::InitBuffer(FixedTextBuffer& Buffer) {
	int result;
	result = Buffer.AddField(sizeof(int) - 1); // courseId : int;
	result = result && Buffer.AddField(sizeof(int) - 1); // studentId : int;
	result = result && Buffer.AddField(sizeof(int) - 1); // NumberOfCreditHourse : int;
	result = result && Buffer.AddField(4); // grade [5];
	return result;
}

int CourseRegistration::Pack(LengthTextBuffer& Buffer) const {
	int result;
	Buffer.Clear();
	result = Buffer.Pack((char*)&courseId);
	result = result && Buffer.Pack((char*)&studentId);
	result = result && Buffer.Pack((char*)&NumberOfCreditHourse);
	result = result && Buffer.Pack(this->grade);
	return result;
}

int CourseRegistration::Unpack(LengthTextBuffer& Buffer) {
	Clear();
	int result;
	result = Buffer.Unpack((char*)&courseId);
	result = result && Buffer.Unpack((char*)&studentId);
	result = result && Buffer.Unpack((char*)&NumberOfCreditHourse);
	result = result && Buffer.Unpack(this->grade);
	return result;
}

int CourseRegistration::InitBuffer(LengthTextBuffer& Buffer) {
	return 1;
}

int CourseRegistration::Pack(DelimTextBuffer& Buffer) const {
	int result;
	Buffer.Clear();
	result = Buffer.Pack((char*)&courseId);
	result = result && Buffer.Pack((char*)&studentId);
	result = result && Buffer.Pack((char*)&NumberOfCreditHourse);
	result = result && Buffer.Pack(this->grade);
	return result;
}

int CourseRegistration::Unpack(DelimTextBuffer& Buffer) {
	Clear();
	int result;
	result = Buffer.Unpack((char*)&courseId);
	result = result && Buffer.Unpack((char*)&studentId);
	result = result && Buffer.Unpack((char*)&NumberOfCreditHourse);
	result = result && Buffer.Unpack(this->grade);
	return result;
}

int CourseRegistration::InitBuffer(DelimTextBuffer& Buffer) {
	return 1;
}

void CourseRegistration::Print(ostream& stream) {
	stream << "CourseRegistration:\n"
		<< "\t            courseId: " << courseId << "\n"
		<< "\t           studentId: " << studentId << "\n"
		<< "\tNumberOfCreditHourse: " << NumberOfCreditHourse << "\n"
		<< "\t               grade: " << grade << "\n\n"
		<< flush;
}