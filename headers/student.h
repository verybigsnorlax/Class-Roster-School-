// Student Class Declaration

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"
using namespace std;

class Student
{
public:
	
	// Constructors 
	Student();
	Student(string newStudentID, string newFirstName, string newLastName, string newEmailAddress, int newAge, int newNumOfDaysToCompleteCourse[], DegreeProgram newDegreeProgram);

	// Accessor Functions
	string GetStudentID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmailAddress() const;
	int GetAge() const;
	int* GetNumOfDaysToCompleteCourse() const;
	DegreeProgram GetDegreeProgram() const;

	// Mutator Functions
	void SetStudentID(string newStudentID);
	void SetFirstName(string newFirstName);
	void SetLastName(string newLastName);
	void SetEmailAddress(string newEmailAddress);
	void SetAge(int newAge);
	void SetNumOfDaysToCompleteCourse(int newNumofDaysToCompleteCourse[]);
	void SetDegreeProgram(DegreeProgram newDegreeProgram);

	// Print Function
	void print() const;

private:

	// Student class private attributes
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numOfDaysToCompleteCourse[3];
	DegreeProgram degreeProgram;
};

#endif