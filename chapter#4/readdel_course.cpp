#include <fstream>
#include <string.h>
#include <iostream>
#include "courseRegistration.h"

using namespace std;
istream& operator >> (istream& stream, CourseRegistration& cr)
{
	char delim;
	char cousreId[10];
	stream.getline(cousreId, 30, '|');
	cr.setCourseId(atoi(cousreId));
	if (strlen(cousreId) == 0) return stream;

	char studentId[10];
	stream.getline(studentId, 30, '|');
	cr.setStudentId(atoi(studentId));

	char numOfCredit[10];
	stream.getline(numOfCredit, 30, '|');
	cr.setNumberOfCreditHourse(atoi(numOfCredit));

	stream.getline(cr.grade, 30, '|');
	cout << endl << "istream.getline(object, size, '|') ½ÇÇàµÊ" << endl;
	return stream;
}

ostream& operator << (ostream& stream, CourseRegistration& cr)
{ // insert fields into file
	cout << "CourseRegistration °´Ã¼¸¦ Ãâ·ÂÇÑ´Ù" << endl;
	stream << cr.courseId << '|' << cr.studentId << '|'
		<< cr.NumberOfCreditHourse << '|' << cr.grade << '|';
	cout << endl;
	return stream;
}
int main(void) {
	char filename[20];
	CourseRegistration cr;
	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);
	ifstream file(filename, ios::in);
	if (file.fail()) {
		cout << "File open failed!" << endl;
		return 0;
	}
	while (1) {
		file >> cr;
		if (cr.courseId == 0) break;
		cout << cr;
	}
	system("pause");
	return 1;
}
