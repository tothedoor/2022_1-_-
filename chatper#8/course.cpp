#include <fstream>
#include <iomanip>
#include <string.h>
#include "course.h"


int CourseRegistration::getStudentId() {
	return studentId;
}
int CourseRegistration::getCredit() {
	return credit;
}

int CourseRegistration::getCourseId() {
	return courseId;
}

int CourseRegistration::Pack(IOBuffer& buffer) const {
	buffer.Clear();
	buffer.Pack(&courseId, sizeof(courseId));
	buffer.Pack(&studentId, sizeof(studentId));
	buffer.Pack(&credit, sizeof(credit));
	buffer.Pack(&grade, -1);
	return 1;
}

int CourseRegistration::Unpack(IOBuffer& buffer) {
	buffer.Unpack(&courseId, sizeof(courseId));
	buffer.Unpack(&studentId, sizeof(studentId));
	buffer.Unpack(&credit, sizeof(credit));
	buffer.Unpack(&grade, -1);
	return 1;
}

CourseRegistration::CourseRegistration() {
	courseId = 0;
	studentId = 0;
	credit = 0;
	grade[0] = 0;
}

CourseRegistration::CourseRegistration(int courseId, int studentId, int credit, char* grade) {
	this->courseId = courseId;
	this->studentId = studentId;
	this->credit = credit;
	strcpy(this->grade, grade);
}

ostream& CourseRegistration::PrintLine(ostream& stream) {
	stream.setf(ios::right, ios::adjustfield);
	stream << studentId << '\t';
	stream.setf(ios::right, ios::adjustfield);
	stream << '\t' << setw(6) << courseId << '\t';
	stream.setf(ios::left, ios::adjustfield);
	stream << credit << '\t' << setw(6) << grade << endl;
	return stream;
}