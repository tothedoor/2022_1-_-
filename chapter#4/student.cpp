#include <string.h>
#include "student.h"
#include <iostream>
using namespace std;
Student::Student()
{//constructor
    Identifier = 0;
    Name[0] = 0;
    Address[0] = 0;
    DateOfFirstEnrollment[0] = 0;
    NumberOfCreditHourse = 0;
}

Student &Student::operator=(const Student& student)
{
    Identifier = student.Identifier;
    strcpy(Name, student.Name);
    strcpy(Address, student.Address);
    strcpy(DateOfFirstEnrollment, student.DateOfFirstEnrollment);
    NumberOfCreditHourse = student.NumberOfCreditHourse;

    cout << "assignment::operator = is called." << endl;
    return *this;
}

void Student::setIdentifier(int newIdentifier) {
    this->Identifier = newIdentifier;
}

void Student::setName(char newName[]) {
    strcpy(this->Name, newName);
}

void Student::setAddress(char newAddr[]) {
    strcpy(this->Address, newAddr);
}

void Student::setDateOfFirstEnrollment(char newDate[]) {
    strcpy(this->DateOfFirstEnrollment, newDate);
}

void Student::setNumberOfCreditHourse(int newValue) {
    this->NumberOfCreditHourse = newValue;
}

void Student::addCreditHourse(int value) {
    this->NumberOfCreditHourse += value;
}