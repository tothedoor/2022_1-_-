/*
교재: 367, 20번 programming project
Ledger 대신에 Student, Journal 대신에 course registration class를 정의한다.
*/
#include "recfile.h"
#include "stdlib.h"
#include <fstream>
#include <string.h>
#include "length.h"
#include "studentprocess.h"

int main(void)
{
	Student s1(1, "Yang", "Busan", "2017", 80);
	Student s2(2, "Minkyu", "Busan", "2018", 60);
	Student s3(3, "Mike", "USA", "2019", 55);
	Student s4(4, "John", "Canada", "2020", 50);
	Student s5(5, "Cathy", "France", "2021", 66);
	
	s1.Print(cout);
	cout << endl;
	s1.PrintHeader(cout);
	cout << endl;
	s1.PrintNumOfCredit(cout);
	/*
	CourseRegistration J1(101, 1271, "02/02/86", "Auto expense", -78.70);
	//...

	LengthFieldBuffer Lbuffer;
	RecordFile<Student> studentFile(Lbuffer);
	int result = studentFile.Create("Transcript.dat", ios::out);
	cout << "Create file " << result << endl;
	if (!result)
	{
		cout << "Unable to Create file " << "Transcript.dat" << endl;
		return 0;
	}
	studentFile.Write(L1);
	//

	studentFile.Close();

	LengthFieldBuffer Jbuffer;
	RecordFile<CourseRegistration> courseRegistrationFile(Jbuffer);
	int flag = courseRegistrationFile.Create("journal.dat", ios::out);
	cout << "Create file " << flag << endl;
	if (!flag)
	{
		cout << "Unable to Create file " << "journal.dat" << endl;
		return 0;
	}
	courseRegistrationFile.Write(J1);
    // ...
	courseRegistrationFile.Close();

	int res;
	RecordFile<Student> sFile(Lbuffer);
	sFile.Open("Transcript.dat", ios::in);
	Student student;
	while (1)
	{
		res = sFile.Read(student);
		if (res <= 0) break;
		cout << "Transcript" << endl;
		student.Print(cout);
	}

	RecordFile<CourseRegistration> cFile(Jbuffer);
	cFile.Open("journal.dat", ios::in);
	CourseRegistration journal;
	while (1)
	{
		res = cFile.Read(journal);
		if (res <= 0) break;
		journal.PrintLine(cout);
	}

	cout << "Posting " << endl;
	StudentProcess Posting;

	Posting.PostTransactions("Student.dat", "CourseRegistration.dat", "Transcript.txt");
	//Modify to show the file Transcript.txt
	char ch;
	fstream TranscriptJournal;
	TranscriptJournal.open("Transcript.txt", ios::in);
	while (1) {
		TranscriptJournal >> ch;
		if (TranscriptJournal.fail()) break;
		cout << ch;
	}
	//Modify to show Transcript.Print();
	cout << "Showing the new account balances for the month" << endl;
	sFile.Open("Transcript.dat", ios::in);
	//*
	while (1)
	{
		res = sFile.Read(student);
		if (res <= 0) break;
		cout << "Transcript" << endl;
		student.Print(cout);
	}
	*/
	system("pause");
	return 1;
}