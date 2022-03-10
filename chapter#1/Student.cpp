#include "Student.h"

Student &Student::operator=(const Student &student)
{
    Identifier = student.Identifier;
    strcpy(Name, student.Name);
    strcpy(Address, student.Address);
    strcpy(DateOfFirstEnrollment, student.DateOfFirstEnrollment);
    NumberOfCreditHourse = student.NumberOfCreditHourse;

    cout << "assignment::operator = is called." << endl;
    return *this;
}