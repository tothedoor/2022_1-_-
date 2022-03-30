// test.cc// Copyright 1997, Gregory A. Riccardi
// 4장 과제2: while(1) { } 문을 완성한다.
#include <fstream>
#include <string.h>
#include <iomanip>
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"
#include "person.h"

#include "student.h"
#include "courseRegistration.h"
#include <vector>

using namespace std;

int testFixText()
{
	Person person;
	FixedTextBuffer Buff(6);
	Person::InitBuffer(Buff);
	strcpy(person.LastName, "Ames      ");
	strcpy(person.FirstName, "Mary      ");
	strcpy(person.Address, "123 Maple      ");
	strcpy(person.City, "Stillwater     ");
	strcpy(person.State, "OK");
	strcpy(person.ZipCode, "74075    ");
	person.Print(cout);
	person.Pack(Buff);
	Buff.Print(cout);
	ofstream TestOut("fixtext.dat", ios::out | ios::binary);
	Buff.Write(TestOut);
	
	TestOut.close();

	ifstream TestIn("fixtext.dat", ios::in | ios::binary);
	FixedTextBuffer InBuff(6);
	Person::InitBuffer(InBuff);
	Buff.Read(TestIn);
	person.Unpack(Buff);
	person.Print(cout);

	char filename[20];	
	int count;
	Student* studentList;
	strcpy(filename, "fixtextStudent.dat");
	FixedTextBuffer studentBuff(5);
	Student::InitBuffer(studentBuff);

	while (1)
	{
		
		int select;
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Person object records : ";
			cin >> count;
			studentList = new Student[count];
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> studentList[i];
			}
			break;
		case 2:
			// to display the array of Person objects into screen
			for (int i = 0; i < count; i++)
			{
				studentList[i].Print(cout);
			}
			break;
		case 3:
		{
			// to write the array of Person objects into a file
			ofstream fostream(filename, ios::out | ios::binary);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Student::InitBuffer(studentBuff);
			for (int i = 0; i < count; i++)
			{
				studentBuff.Print(cout);
				cout << "pack student" << i << "... result: " << studentList[i].Pack(studentBuff) << endl;
				studentBuff.Print(cout);
				studentBuff.Write(fostream);
			}
			fostream.close();
			break;
		}
		case 4:
		{
			// to read the array of Person records from the file
			ifstream fistream(filename, ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Student::InitBuffer(studentBuff);
			for (int i = 0; i < count; i++)
			{
				Student student;
				cout << "read " << studentBuff.Read(fistream) << endl;
				cout << "unpack " << student.Unpack(studentBuff) << endl;
				student.Print(cout);
			}
			fistream.close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
	}
		
}


int testLenText()
{
	char filename[20];
	cout << "\nTesting LengthTextBuffer" << endl;
	Person person;
	LengthTextBuffer Buff;
	Person::InitBuffer(Buff);
	strcpy(person.LastName, "Ames");
	strcpy(person.FirstName, "Mary");
	strcpy(person.Address, "123 Maple");
	strcpy(person.City, "Stillwater");
	strcpy(person.State, "OK");
	strcpy(person.ZipCode, "74075");
	person.Print(cout);
	Buff.Print(cout);
	cout << "pack person " << person.Pack(Buff) << endl;
	Buff.Print(cout);
	ofstream TestOut("lentext.dat", ios::out | ios::binary);
	Buff.Write(TestOut);
	Buff.Write(TestOut);
	strcpy(person.FirstName, "Dave");
	person.Print(cout);
	person.Pack(Buff);
	Buff.Write(TestOut);
	TestOut.close();
	ifstream TestIn("lentext.dat", ios::in | ios::binary);
	LengthTextBuffer InBuff;
	Person::InitBuffer(InBuff);
	cout << "read " << Buff.Read(TestIn) << endl;
	cout << "unpack " << person.Unpack(Buff) << endl;
	person.Print(cout);
	cout << "read " << Buff.Read(TestIn) << endl;
	cout << "unpack " << person.Unpack(Buff) << endl;
	person.Print(cout);
	cout << "read " << Buff.Read(TestIn) << endl;
	cout << "unpack " << person.Unpack(Buff) << endl;
	person.Print(cout);
	
	int count;
	Student* studentList;
	strcpy(filename, "lentextStudent.dat");

	while (1)
	{
		
		int select;
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Student object records : ";
			cin >> count;
			studentList = new Student[count];
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> studentList[i];
			}
			break;
		case 2:
			// to display the array of Person objects into screen
			for (int i = 0; i < count; i++)
			{
				studentList[i].Print(cout);
			}
			break;
		case 3:
		{
			// to write the array of Person objects into a file
			ofstream fostream(filename, ios::out | ios::binary);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Student::InitBuffer(InBuff);
			for (int i = 0; i < count; i++)
			{
				InBuff.Print(cout);
				cout << "pack student" << i << "... result: " << studentList[i].Pack(InBuff) << endl;
				InBuff.Print(cout);
				InBuff.Write(fostream);
			}
			fostream.close();
			break;
		}
		case 4:
		{
			// to read the array of Person records from the file
			ifstream fistream(filename, ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Person::InitBuffer(InBuff);
			for (int i = 0; i < count; i++)
			{	
				Student student;
				cout << "read " << InBuff.Read(fistream) << endl;
				cout << "unpack " << student.Unpack(InBuff) << endl;
				student.Print(cout);
			}
			fistream.close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
		
	}
}


int testDelText()
{
	char filename[20];
	cout << "\nTesting DelimTextBuffer" << endl;
	Person person;
	strcpy(person.LastName, "Ames");
	strcpy(person.FirstName, "Mary");
	strcpy(person.Address, "123 Maple");
	strcpy(person.City, "Stillwater");
	strcpy(person.State, "OK");
	strcpy(person.ZipCode, "74075");

	// student 추가
	Student student;
	student.Identifier = 1;
	strcpy(student.Name, "Yang");
	strcpy(student.Address, "SunChang");
	strcpy(student.DateOfFirstEnrollment, "2017");
	student.NumberOfCreditHourse = 100;
	// courseRegistration 추가
	CourseRegistration courseRegistration;
	courseRegistration.courseId = 1;
	courseRegistration.studentId = 1;
	courseRegistration.NumberOfCreditHourse = 100;
	strcpy(courseRegistration.grade, "A+");
	//student, courseRegistration Print 함수 호출 추가
	person.Print(cout);
	student.Print(cout);
	courseRegistration.Print(cout);
	cout << "------------------------------------\n\n";

	// student pack, unpack, write, read test
	DelimTextBuffer Buff;
	Student::InitBuffer(Buff);
	Buff.Print(cout);
	cout << "pack student " << student.Pack(Buff) << endl;
	Buff.Print(cout);
	ofstream TestOut("deltextstudent.txt", ios::out | ios::binary | ios::trunc);
	Buff.Write(TestOut);
	TestOut.close();

	ifstream TestIn("deltextstudent.txt", ios::in | ios::binary);
	DelimTextBuffer InBuff;
	Student::InitBuffer(InBuff);
	cout << "read " << Buff.Read(TestIn) << endl;
	cout << "unpack " << student.Unpack(Buff) << endl;
	student.Print(cout);
	cout << "-----------------------------------------\n" << endl;

	// courseRegistration pack, unpack, write ,read test
	DelimTextBuffer CourseBuff;
	CourseRegistration::InitBuffer(CourseBuff);
	CourseBuff.Print(cout);
	cout << "pack courseRegistration " << courseRegistration.Pack(CourseBuff) << endl;
	CourseBuff.Print(cout);
	ofstream CourseTestOut("deltextcourse.txt", ios::out | ios::binary | ios::trunc);
	CourseBuff.Write(CourseTestOut);
	CourseTestOut.close();

	ifstream CourseTestIn("deltextcourse.txt", ios::in | ios::binary);
	DelimTextBuffer CourseInBuff;
	Student::InitBuffer(CourseInBuff);
	cout << "read " << CourseBuff.Read(CourseTestIn) << endl;
	cout << "unpack " << courseRegistration.Unpack(CourseBuff) << endl;
	courseRegistration.Print(cout);
	cout << "-----------------------------------------\n" << endl;

	/*Person::InitBuffer(Buff);
	Buff.Print(cout);
	cout << "pack person " << person.Pack(Buff) << endl;
	Buff.Print(cout);
	ofstream TestOut("deltextperson.txt", ios::out | ios::binary | ios::trunc);
	Buff.Write(TestOut);
	Buff.Write(TestOut);
	strcpy(person.FirstName, "Dave");
	person.Print(cout);
	person.Pack(Buff);
	Buff.Write(TestOut);
	TestOut.close();
	ifstream TestIn("deltextperson.txt", ios::in | ios::binary);
	DelimTextBuffer InBuff;	Person::InitBuffer(InBuff);
	cout << "read " << Buff.Read(TestIn) << endl;
	cout << "unpack " << person.Unpack(Buff) << endl;
	person.Print(cout);
	cout << "read " << Buff.Read(TestIn) << endl;
	cout << "unpack " << person.Unpack(Buff) << endl;
	person.Print(cout);
	cout << "read " << Buff.Read(TestIn) << endl;
	cout << "unpack " << person.Unpack(Buff) << endl;
	person.Print(cout);*/

	
	Student *studentList;
	int count;
	strcpy(filename, "deltextStudent.txt");

	while (1)
	{
		 int select;
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Person object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			studentList = new Student[count];
			for (int i = 0; i < count; i++)
			{
				Student student;
				cin >> student;
				studentList[i] = student;
			}
			break;
		case 2:
			// to display the array of Person objects into screen
			for (int i = 0; i < count; i++)
			{
				studentList[i].Print(cout);
			}
			break;
		case 3:
		{
			// to write the array of Person objects into a file
			ofstream fostream(filename, ios::out | ios::in);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Student::InitBuffer(InBuff);
			for (int i = 0; i < count; i++)
			{
				InBuff.Print(cout);
				cout << "pack student" << i << "... result: " << studentList[i].Pack(InBuff) << endl;
				InBuff.Print(cout);
				InBuff.Write(fostream);
			}
			fostream.close();
			break;
		}
		case 4:
		{
			// to read the array of Person records from the file
			ifstream fistream(filename, ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}

			Student::InitBuffer(InBuff);
			for (int i = 0; i < count; i++)
			{
				cout << "read " << InBuff.Read(fistream) << endl;
				cout << "unpack " << student.Unpack(InBuff) << endl;
				student.Print(cout);
			}
			fistream.close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
	}
		
	return 1;
}


int main(void)
{
	testFixText();
	//testLenText();
	//testDelText();
	system("pause");
	return 1;
}
