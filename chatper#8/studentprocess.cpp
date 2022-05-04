#include "studentprocess.h"

StudentProcess::StudentProcess()
: MasterTransactionProcess<int>(), studentFile(sbuffer), courseRegistrationFile(cbuffer) {}

int StudentProcess::InitializeList(int listNumber, char* listName) {
	studentNumber[listNumber] = LowStudentId;
	switch (listNumber) {
	case 1:
		return studentFile.Open(listName, ios::in);
	case 2:
		return courseRegistrationFile.Open(listName, ios::in);
	}
	return 0;
}

int StudentProcess::InitializeOutput(char* outputListName) {
	OutputList.open(outputListName);
	return 1;
}

int StudentProcess::NextItemInList(int listNumber) {
	switch (listNumber) {
	case 1:
		return NextItemInStudent();
	case 2:
		return NextItemInCourseRegistration();
	}
	return 0;
}

int StudentProcess::Item(int listNumber) {
	return studentNumber[listNumber];
}

int StudentProcess::ProcessItem(int listNumber) {
	switch (listNumber) {
	case 1:
		student.PrintHeader(OutputList);
	case 2:
		courseRegistration.PrintLine(OutputList);
	}
	return 1;
}

int StudentProcess::ProcessNewMaster() {
	student.PrintHeader(OutputList);
	return 1;
}

int StudentProcess::ProcessCurrentMaster() {
	student.addNumofCredit(courseRegistration.getCredit());
	return 1;
}

int StudentProcess::ProcessEndMaster() {
	student.PrintNumOfCredit(OutputList);
	return 1;
}

int StudentProcess::ProcessTransactionError() {
	cerr << "Error Student for course registration" << endl;
	cerr << courseRegistration.getStudentId();
	courseRegistration.PrintLine(cerr);
	return 1;
}

int StudentProcess::FinishUp() {
	studentFile.Close();
	courseRegistrationFile.Close();
	OutputList.close();
	return 1;
}

int StudentProcess::NextItemInStudent() {
	int res = studentFile.Read(student);
	if (res <= 0) {
		studentNumber[1] = HighStudentId;
		return 0;
	}
	if (student.getStudentId() <= studentNumber[1]) {
		cerr << "Student Number out of order" << endl; exit(0);
	}
	studentNumber[1] = student.getStudentId();
	return 1;
}

int StudentProcess::NextItemInCourseRegistration() {
	int res = courseRegistrationFile.Read(courseRegistration);
	if (res <= 0) {
		studentNumber[2] = HighStudentId;
		return 0;
	}
	if (courseRegistration.getStudentId() < studentNumber[2]) {
		cerr << "course registration out of order" << endl; exit(0);
	}
	studentNumber[2] = courseRegistration.getStudentId();
	return 1;
}

int StudentProcess::LowStudentId = -1;
int StudentProcess::HighStudentId = 9999;