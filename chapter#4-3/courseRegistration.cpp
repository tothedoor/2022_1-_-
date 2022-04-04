#include "courseRegistration.h"

CourseRegistration::CourseRegistration() { Clear(); }
CourseRegistration::CourseRegistration(CourseRegistration& course) {
	courseId = course.courseId;
	studentId = course.studentId;
	NumberOfCreditHourse = course.NumberOfCreditHourse;
	strcpy(grade, course.grade);
}

void CourseRegistration::Clear() {
	courseId = 0;
	studentId = 0;
	NumberOfCreditHourse = 0;
	grade[0] = 0;
}

int CourseRegistration::Pack(IOBuffer& Buffer) const {
	int numBytes;
	Buffer.Clear();

	char courseId_char[10];
	snprintf(courseId_char, 10, "%d", courseId);
	numBytes = Buffer.Pack(courseId_char);
	if (numBytes == -1) return FALSE;

	char studentId_char[10];
	snprintf(studentId_char, 10, "%d", studentId);
	numBytes = Buffer.Pack(studentId_char);
	if (numBytes == -1) return FALSE;

	char NumberOfCredit_char[10];
	snprintf(NumberOfCredit_char, 10, "%d", NumberOfCreditHourse);
	numBytes = Buffer.Pack(NumberOfCredit_char);
	if (numBytes == -1) return FALSE;

	numBytes = Buffer.Pack(grade);
	if (numBytes == -1) return FALSE;

	return TRUE;
}

int CourseRegistration::Unpack(IOBuffer& Buffer) {
	Clear();
	int numBytes;

	char courseId_char[10];
	numBytes = Buffer.Unpack(courseId_char);
	if (numBytes == -1) return FALSE;
	courseId = atoi(courseId_char);

	char studentId_char[10];
	numBytes = Buffer.Unpack(studentId_char);
	if (numBytes == -1) return FALSE;
	studentId = atoi(studentId_char);

	char NumberOfCredit_char[10];
	numBytes = Buffer.Unpack(NumberOfCredit_char);
	if (numBytes == -1) return FALSE;
	NumberOfCreditHourse = atoi(NumberOfCredit_char);
	
	numBytes = Buffer.Unpack(grade);
	if (numBytes == -1) return FALSE;

	return TRUE;
}

void CourseRegistration::Print(ostream& stream, char* label) const {
	if (label == 0) stream << "CourseRegistration:";
	else stream << label;
	stream << "\n\t               courseID: " << courseId;
	stream << "\n\t              studentId: " << studentId;
	stream << "\n\t Number Of CreditHourse: " << NumberOfCreditHourse;
	stream << "\n\                   grade: " << grade << "\n";
}

istream& operator>>(istream& stream, CourseRegistration& course) {
	cout << "Enter courseId: " << flush;
	char courseId[10];
	stream.getline(courseId, 11);
	course.courseId = atoi(courseId);

	cout << "Enter studentId: " << flush;
	char studentId[10];
	stream.getline(studentId, 11);
	course.studentId = atoi(studentId);

	cout << "Enter Number of CreditHourse: " << flush;
	char NumOfCredit[10];
	stream.getline(NumOfCredit, 11);
	course.NumberOfCreditHourse = atoi(NumOfCredit);

	cout << "Enter grade: " << flush;
	stream.getline(course.grade, 6);

	return stream;
}

ostream& operator<<(ostream& stream, CourseRegistration& course)
{
	stream << "CourseRegistration's Info: ";
	stream << "\n\t           courseId: " << course.courseId
		<< "\n\t             studentId: " << course.studentId
		<< "\n\tNumber Of CreditHourse: " << course.NumberOfCreditHourse
		<< "\n\                  grade: " << course.grade << "\n\n";
	return stream;
}