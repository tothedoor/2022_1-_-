#ifndef STUDENT
#define STUDENT

class Student
{
public:
	// data members
	int Identifier;
	char Name[11];
	char Address[16];
	char DateOfFirstEnrollment[8];
	int NumberOfCreditHourse;
	// method
	Student();							 // default constructor
	Student &operator=(const Student &); // assign operator

	void setIdentifier(int newIdentifier);
	void setName(char newName[]);
	void setAddress(char newAddr[]);
	void setDateOfFirstEnrollment(char newDate[]);
	void setNumberOfCreditHourse(int newValue);

	void addCreditHourse(int value);
};
#endif