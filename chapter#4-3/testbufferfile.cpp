//학번: 201724505
//이름: 양민규
//github id: tothedoor
#include "teststudent.h"
#include "courseRegistration.h"
#include "buffile.h"
#include "length.h"
#include "fixfld.h"
#include "delim.h"
#include <typeinfo>

void testBuffer(IOBuffer& Buff);
int main(int argc, char ** argv)
{	
	while (1) {
		int optionNum;
		cout << "\nSelect kind of Buffer to test.\n"
			<< "[1]:LengthFieldBuffer   [2]:DelimFieldBuffer   [3]:FixedFieldBuffer   [else]:exit\n"
			<< "Enter number: ";
		cin >> optionNum;
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		switch (optionNum) {
		case 1:
			cout << "<Test LengthFieldBuffer!!!>\n";
			testBuffer(LengthFieldBuffer());
			break;
		case 2:
			cout << "<Test DelimFieldBuffer!!!>\n";
			testBuffer(DelimFieldBuffer());
			break;
		case 3: {
			cout << "<Test FixedFieldBuffer!!!>\n";
			FixedFieldBuffer Buff = FixedFieldBuffer(4);
			// field Size를 추가하고 testBuffer에 인자로 전달하여 test 수행
			Buff.AddField(39);
			Buff.AddField(9);
			Buff.AddField(9);
			Buff.AddField(39);
			testBuffer(Buff);
			break;
		}
		default:
			cout << "exit...\n";
			exit(0);
			break;
		}
	}
	return 1;
}

void testBuffer(IOBuffer& Buff) {
	int count, select;
	char filename[20];
	Student student;
	Student* stable[10];
	CourseRegistration course;
	CourseRegistration* ctable[10];

	int result;
	int recaddr;
	int objtype;
	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);
	cout << "Select type of Oject to test!\n"
		<< "[1]:Student   [2]:CourseRegistration\n";
	cin >> objtype;
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	if (objtype == 1) { // student
		while (1)
		{
			cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
			cin >> select;

			switch (select) {
			case 1:
				//to store a array of Student objects by inputing
				cout << "the number of Student object records : ";
				cin >> count;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				for (int i = 0; i < count; i++)
				{
					cin >> student;
					student.Print(cout);
					stable[i] = new Student(student);			// copy constructor should be implemented
				}
				break;
			case 2:
				// to display the array of Student objects into screen  
				for (int i = 0; i < count; i++)
				{
					cout << *stable[i];// operator<< (operator overloading) should be implemented
				}
				break;
			case 3:
			{

				// to write the array of Student objects into a file
				//Buff . Print (cout);
				BufferFile TestOut(Buff);
				result = TestOut.Create(filename, ios::in | ios::out);
				cout << "create file " << result << endl;
				if (!result)
				{
					cout << "Unable to create file " << filename << endl;
				}
				/*
				result = TestOut.Open(myfile, ios::in | ios::out);
				cout << "open file " << result << endl;
				if (!result)
				{
					cout << "Unable to open file " << myfile << endl;
					return;
				}
				*/
				//}
				for (int i = 0; i < count; i++)
				{
					stable[i]->Print(cout);
					stable[i]->Pack(Buff);
					recaddr = TestOut.Write();
					cout << "Student R[" << i << "] at recaddr " << recaddr << endl;

					delete(stable[i]);//return the object created by new()
				}

				break;
			}
			case 4:
			{
				// to read the array of Student records from the file
				BufferFile TestIn(Buff);
				TestIn.Open(filename, ios::in);
				//result = TestIn . ReadHeader ();
				//cout <<"read header "<<result<<endl;

				for (int i = 0; i < count; i++)
				{
					stable[i] = new Student();
					recaddr = TestIn.Read();
					stable[i]->Unpack(Buff);
					stable[i]->Print(cout);
				}

				/* result는 55번 line에서 BufferFile의 생성이 성공적으로 이뤄졌는지 확인하는
				   변수로 사용됩니다. (성공하면 1, 아니면 0) 때문에 101번 라인의 if-else문의 출력문들은
				   어떤 의미로 사용되는지 파악되지 않아 그대로 두었습니다. 교수님께서 피드백 해주시면
				   큰 도움이 될 것 같습니다.*/
				if (result != -1) cout << "Read past end of file! Error." << endl;
				else cout << "Read past end of file failed! Correct." << endl;

				break;
			}
			default:
				// others
				return;
				break;

				//*/
			}
		}
	}
	else { // CourseRegistration
		while (1)
		{
			cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
			cin >> select;

			switch (select) {
			case 1:
				//to store a array of Student objects by inputing
				cout << "the number of CourseRegistration object records : ";
				cin >> count;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				for (int i = 0; i < count; i++)
				{
					cin >> course;
					course.Print(cout);
					ctable[i] = new CourseRegistration(course);
				}
				break;
			case 2:
				// to display the array of CourseRegistration objects into screen  
				for (int i = 0; i < count; i++)
				{
					cout << *ctable[i];
				}
				break;
			case 3:
			{

				// to write the array of Student objects into a file
				//Buff . Print (cout);
				BufferFile TestOut(Buff);
				result = TestOut.Create(filename, ios::in | ios::out);
				cout << "create file " << result << endl;
				if (!result)
				{
					cout << "Unable to create file " << filename << endl;
				}
				/*
				result = TestOut.Open(myfile, ios::in | ios::out);
				cout << "open file " << result << endl;
				if (!result)
				{
					cout << "Unable to open file " << myfile << endl;
					return;
				}
				*/
				//}
				for (int i = 0; i < count; i++)
				{
					ctable[i]->Print(cout);
					ctable[i]->Pack(Buff);
					recaddr = TestOut.Write();
					cout << "CourseRegistration R[" << i << "] at recaddr " << recaddr << endl;

					delete(ctable[i]);//return the object created by new()
				}

				break;
			}
			case 4:
			{
				// to read the array of Student records from the file
				BufferFile TestIn(Buff);
				TestIn.Open(filename, ios::in);
				//result = TestIn . ReadHeader ();
				//cout <<"read header "<<result<<endl;

				for (int i = 0; i < count; i++)
				{
					ctable[i] = new CourseRegistration();
					recaddr = TestIn.Read();
					ctable[i]->Unpack(Buff);
					ctable[i]->Print(cout);
				}

				if (result != -1) cout << "Read past end of file! Error." << endl;
				else cout << "Read past end of file failed! Correct." << endl;

				break;
			}
			default:
				// others
				return;
				break;

				//*/
			}
		}
	}
	
}
