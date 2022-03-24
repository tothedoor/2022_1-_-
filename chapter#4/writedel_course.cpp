#include <fstream>
#include "courseRegistration.h"
#include <iostream>

using namespace std;

ostream& operator << (ostream& stream, CourseRegistration& cr)
{ 
	stream << cr.courseId << '|' << cr.studentId << '|' 
		   << cr.NumberOfCreditHourse << '|' << cr.grade << '|';
	return stream;
}
istream& operator >> (istream& stream, CourseRegistration& cr)
{
	cout << "Enter Course Identifier or <cr>: " << flush;
	char coureIdentifier[10];
	stream.getline(coureIdentifier, 10);
	cr.setCourseId(atoi(coureIdentifier));
	if (cr.courseId == 0)
		return stream;

	cout << "Enter Student Identifier: " << flush;
	char studentIdentifier[10];
	stream.getline(studentIdentifier, 10);
	cr.setStudentId(atoi(studentIdentifier));

	cout << "Enter Number of CreditHourse: " << flush;
	char numOfCredit[10];
	stream.getline(numOfCredit, 10);
	cr.setNumberOfCreditHourse(atoi(numOfCredit));

	cout << "Enter grade: " << flush; stream.getline(cr.grade, 20);
	return stream;
}
int main(void) {
	char filename[20];
	CourseRegistration cr;
	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);
	ofstream file(filename, ios::out);
	if (file.fail()) {
		cout << "File open failed!" << endl;
		return 0;
	}
	while (1) {
		cin >> cr;
		if (cr.courseId == 0) break;
		// write person to file
		file << cr;

	}

	system("pause");

	return 0;
}
