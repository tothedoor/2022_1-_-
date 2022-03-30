#include <string.h>
#include <string>
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

    return *this;
}

istream& operator >> (istream& stream, Student& student) { 
    cout << "-------------------------------------------------------\n" << flush;
    cout << "Enter Identifier: " << flush;
    char id[5];
    stream.getline(id, 10);
    student.Identifier = atoi(id);
    cout << "Enter Name: " << flush;
    stream.getline(student.Name, 30);
    cout << "Enter Address: " << flush;
    stream.getline(student.Address, 50);
    cout << "Enter Date of first enrollment: " << flush;
    stream.getline(student.DateOfFirstEnrollment, 50);
    cout << "Enter number of CreditHourse: " << flush;
    char numofCredit[15];
    stream.getline(numofCredit, 30);
    student.NumberOfCreditHourse = atoi(numofCredit);
    return stream;

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

// chapter 4-2 에서 추가된 코드
void Student::Clear() {
    Identifier = 0;
    Name[0] = 0;
    Address[0] = 0;
    DateOfFirstEnrollment[0] = 0;
    NumberOfCreditHourse = 0;
}

int Student::Pack(FixedTextBuffer& Buffer) const {
    int result;
    Buffer.Clear();
    result = Buffer.Pack((char*)&Identifier);
    result = result && Buffer.Pack(this->Name);
    result = result && Buffer.Pack(this->Address);
    result = result && Buffer.Pack(this->DateOfFirstEnrollment);
    result = result && Buffer.Pack((char*)&NumberOfCreditHourse);
    return result;
}

int Student::Unpack(FixedTextBuffer& Buffer) {
    Clear();
    int result;
    result = Buffer.Unpack((char*)&Identifier);
    result = result && Buffer.Unpack(this->Name);
    result = result && Buffer.Unpack(this->Address);
    result = result && Buffer.Unpack(this->DateOfFirstEnrollment);
    result = result && Buffer.Unpack((char*)&NumberOfCreditHourse);
    return result;
}

int Student::InitBuffer(FixedTextBuffer& Buffer) {
    int result;
    result = Buffer.AddField(sizeof(int)-1); // Identifier : int;
    result = result && Buffer.AddField(14); // Name [15];
    result = result && Buffer.AddField(14); // Addrestt [15];
    result = result && Buffer.AddField(14); // DateOfFirstEnroll [15];
    result = result && Buffer.AddField(sizeof(int) - 1); // NumberofCreditHourse : int;
    return result;
}

int Student::Pack(LengthTextBuffer& Buffer) const {
    int result;
    Buffer.Clear();
    result = Buffer.Pack((char*)&Identifier);
    result = result && Buffer.Pack(Name);
    result = result && Buffer.Pack(Address);
    result = result && Buffer.Pack(DateOfFirstEnrollment);
    result = result && Buffer.Pack((char*)&NumberOfCreditHourse);
    return result;
}

int Student::Unpack(LengthTextBuffer& Buffer) {
    int result;
    result = Buffer.Unpack((char*)&Identifier);
    result = result && Buffer.Unpack(Name);
    result = result && Buffer.Unpack(Address);
    result = result && Buffer.Unpack(DateOfFirstEnrollment);
    result = result && Buffer.Unpack((char*)&NumberOfCreditHourse);
    return result;
}

int Student::InitBuffer(LengthTextBuffer& Buffer) {
    return 1;
}

int Student::Pack(DelimTextBuffer& Buffer) const {
    int result;
    Buffer.Clear();
    result = Buffer.Pack((char*)&Identifier);
    result = result && Buffer.Pack(Name);
    result = result && Buffer.Pack(Address);
    result = result && Buffer.Pack(DateOfFirstEnrollment);
    result = result && Buffer.Pack((char*)&NumberOfCreditHourse);
    return result;
}

int Student::Unpack(DelimTextBuffer& Buffer) {
    int result;
    result = Buffer.Unpack((char*)&Identifier);
    result = result && Buffer.Unpack(Name);
    result = result && Buffer.Unpack(Address);
    result = result && Buffer.Unpack(DateOfFirstEnrollment);
    result = result && Buffer.Unpack((char*)&NumberOfCreditHourse);
    return result;
}

int Student::InitBuffer(DelimTextBuffer& Buffer) {
    return 1;
}

void Student::Print(ostream& stream) {
    stream << "Student:\n"
        << "\t              Identifier: " << Identifier << "\n"
        << "\t                    Name: " << Name << "\n"
        << "\t                 Address: " << Address << "\n"
        << "\tDate of First Enrollment: " << DateOfFirstEnrollment << "\n"
        << "\t Number of Credit Hourse: " << NumberOfCreditHourse << "\n\n"
        << flush;
}