// Studen Class Method Defintions

#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Default Constructor
// Return Type: None
// Purpose of the default constructor is to initialize the variables upon class instantiation with no parameters
Student::Student()
{
	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = 0;
	numOfDaysToCompleteCourse[0] = 0;
	numOfDaysToCompleteCourse[1] = 0;
	numOfDaysToCompleteCourse[2] = 0;
}

// Paramterized Constructor
// Return type: None
// Purpose of this function is to set the class attributes to the matching parameters upon instantiation
Student::Student(string newStudentID, string newFirstName, string newLastName, string newEmailAddress, int newAge, int newNumOfDaysToCompleteCourse[], DegreeProgram newDegreeProgram)
{
	SetStudentID(newStudentID);
	SetFirstName(newFirstName);
	SetLastName(newLastName);
	SetEmailAddress(newEmailAddress);
	SetAge(newAge);
	SetNumOfDaysToCompleteCourse(newNumOfDaysToCompleteCourse);
	SetDegreeProgram(newDegreeProgram);
}

// Get Student ID Function
// Return type: string
// An accessor function that returns the student ID
string Student::GetStudentID() const
{
	return studentID;
}

// Get First Name Function
// Return type: string
// An accessor function that returns the student's first name
string Student::GetFirstName() const
{
	return firstName;
}

// Get Last Name Function
// Return type: string
// An accessor function that returns the student's last name
string Student::GetLastName() const
{
	return lastName;
}

// Get Email Address Function
// Return type: string
// An accessor function that returns the student's email address
string Student::GetEmailAddress() const
{
	return emailAddress;
}

// Get Age Function
// Return type: int
// An accessor function that returns the student's age
int Student::GetAge() const
{
	return age;
}

// Get Num Of Days To Complete Course Function
// Return type: int array
// An accessor function that returns the array numOfDaysToCompletCourse
int* Student::GetNumOfDaysToCompleteCourse() const
{
	static int arr[3];
	
	for (int i = 0; i < 3; ++i)
	{
		arr[i] = numOfDaysToCompleteCourse[i];
	}

	return arr;
}

// Get Degree Program Function
// Return type: DegreeProgram
// An accessor function that returns the student's degree program name
DegreeProgram Student::GetDegreeProgram() const
{
	return degreeProgram;
}

// Set Student ID Function
// Return type: None
// A mutator function that sets the student's ID to the newly given student ID
void Student::SetStudentID(string newStudentID)
{
	studentID = newStudentID;
}

// Set First Name Function
// Return type: None
// A mutator function that sets the student's first name to the newly given first name
void Student::SetFirstName(string newFirstName)
{
	firstName = newFirstName;
}

// Set Last Name Function
// Return type: None
// A mutator function that sets the student's last name to the newly given last name
void Student::SetLastName(string newLastName)
{
	lastName = newLastName;
}

// Set Email Address Function
// Return type: None
// A mutator function that sets the student's email address to the newly given email address
void Student::SetEmailAddress(string newEmailAddress)
{
	emailAddress = newEmailAddress;
}

// Set Age Function
// Return type: None
// A mutator function that sets the student's age to the newly given age
void Student::SetAge(int newAge)
{
	age = newAge;
}

// Set Num Of Days To Complete Course Function
// Return type: None
// A mutator function that sets the student's numOfDaysToCompleteCourse to the newly given numOfDaysToCompleteCourse
void Student::SetNumOfDaysToCompleteCourse(int newNumOfDaysToCompleteCourse[])
{
	for (int i = 0; i < 3; ++i)
	{
		numOfDaysToCompleteCourse[i] = newNumOfDaysToCompleteCourse[i];
	}
}

// Set Degree Program Function
// Return type: None
// A mutator function that sets the student's degreeProgram to the newly given degreeProgram
void Student::SetDegreeProgram(DegreeProgram newDegreeProgram)
{
	degreeProgram = newDegreeProgram;
}

// Print Function
// Return type: None
// This function prints to the console the student's specific information
void Student::print() const
{
	string degreeName = "";

	cout << "Student ID: " << left << setw(5) << studentID 
		<<  "First Name: " << setw(10) << firstName 
		<<  "Last Name: " << setw(10) << lastName 
		<<  "Email Address: " << setw(25) << emailAddress 
		<< "Age: " << setw(5) << age 
		<< "Days In Course: " << "{" << numOfDaysToCompleteCourse[0] << ", " << numOfDaysToCompleteCourse[1] << ", " << numOfDaysToCompleteCourse[2] << "}" << "   ";

	switch(degreeProgram)
	{
		case DegreeProgram::NETWORK:
			degreeName = "Network";
			break;
		case DegreeProgram::SECURITY:
			degreeName = "Security";
			break;
		case DegreeProgram::SOFTWARE:
			degreeName = "Software";
			break;
		default:
			degreeName = "Degree Undetermined";
			break;
	}

	cout << "Degree Program: " << degreeName << endl;
}