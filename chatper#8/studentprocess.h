#pragma once
#include "mastrans.h"
#include "student.h"
#include "course.h"
#include "recfile.h"
#include "length.h"

class StudentProcess : public MasterTransactionProcess<int>
	// Transcript processing of a Transcript file and a journal file
	// the item type is int to represent an account number
{
public:
	StudentProcess(); // constructor

	// Basic list processing methods
	int InitializeList(int ListNumber, char* listName);
	int InitializeOutput(char* outputListName);
	int NextItemInList(int listNumber); //get next item from this list
	int Item(int listNumber); // return current item from this list
	int ProcessItem(int listNumber); // process the item in this list
	int FinishUp(); // complete the processing

	// master/transaction methods
	virtual int ProcessNewMaster();//  when new master read
	virtual int ProcessCurrentMaster();// each transaction for a master
	virtual int ProcessEndMaster();// after all transactions for a master
	virtual int ProcessTransactionError();// no master for transaction

protected:
	// members
	int MonthNumber; // number of month to be processed
	LengthFieldBuffer sbuffer, cbuffer; // buffers for files
	RecordFile<Student> studentFile; // list 1
	RecordFile<CourseRegistration> courseRegistrationFile;// list 2
	int studentNumber[3]; // current item in each list
	Student student; // current Student Object
	CourseRegistration courseRegistration; // current CourseRegistration object
	ofstream OutputList; // text output file for post method
	static int LowStudentId;// lower than the lowest account number
	static int HighStudentId;// higher than the highest account number

	int NextItemInStudent();
	int NextItemInCourseRegistration();
};