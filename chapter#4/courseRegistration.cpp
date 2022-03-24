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
void CourseRegistration::setCourseId(int courseId) { this->courseId = courseId; }
void CourseRegistration::setStudentId(int studentId) { this->studentId = studentId; }
void CourseRegistration::setNumberOfCreditHourse(int numOfCredit) { this->NumberOfCreditHourse = numOfCredit; }
void CourseRegistration::setGrade(char grade[]) { strcpy(this->grade, grade); }