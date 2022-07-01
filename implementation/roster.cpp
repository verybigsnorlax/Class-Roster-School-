#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Non-Parameterized Default Constructor
// Return type: None
// The constructor will initialize classRosterArray to hold nullptrs
Roster::Roster()
{
	for (int i = 0; i < 5; ++i)
	{
		classRosterArray[i] = nullptr;
	}
}

// Destructor
// Return type: None
// Purpose of the destructor is to free the memory that has been allocated dynamically
Roster::~Roster()
{
	for (int i = 0; i < 5; ++i)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

// Add Student to the Roster Function
// Return type: None
// The purpose of this function is to take the parameters of a student's details and to instantiate a student object to hold the student details, then add student to the roster.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	// Loop through the array
	for (int i = 0; i < 5; ++i)
	{
		// Find the next empty index in the classRosterArray
		if (classRosterArray[i] == nullptr)
		{
			// Create an array to hold the daysInCourse values
			int arr[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
			
			// Dynamically allocate memory in the Roster of a type Student
			classRosterArray[i] = new Student;

			// Using the mutator functions, edit the student object attributes to the given student details
			classRosterArray[i]->SetStudentID(studentID);
			classRosterArray[i]->SetFirstName(firstName);
			classRosterArray[i]->SetLastName(lastName);
			classRosterArray[i]->SetEmailAddress(emailAddress);
			classRosterArray[i]->SetAge(age);
			classRosterArray[i]->SetNumOfDaysToCompleteCourse(arr);
			classRosterArray[i]->SetDegreeProgram(degreeProgram);

			// Break out of the loop, as no further instructions are needed
			break;
		}
	}
}

// Remove Student from the Roster Function
// Return type: None
// The purpose of this function is to take the given student ID and if there is data on a student with that student ID, remove the student from the roster
void Roster::remove(string studentID)
{
	bool found = false;

	// Loop through the Student Roster
	for (int i = 0; i < 5; ++i)
	{
		// If we reached the end of the loop or the student we are on has no information break out of the loop
		if (classRosterArray[i] == nullptr) break;

		// If a student with the given student ID is found in the Roster
		if (classRosterArray[i]->GetStudentID() == studentID)
		{
			found = true;

			// Remove the student with the matching student ID
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;

			// If the deleted student is not at the end of the Roster
			if (i + 1 != 5)
			{
				// If there are more students that come after the deleted student, move the students up the Rosters
				if (classRosterArray[i + 1] != nullptr)
				{
					for (int j = i; j < 4; ++j)
					{
						// Move the student up on the Roster
						classRosterArray[j] = classRosterArray[j + 1];

						// If the final student was moved up, set the last pointer to nullptr
						if (j == 3) classRosterArray[j + 1] = nullptr;
					}
				}
			}
			break;
		}
	}

	// If a student with the student ID was not found, print an error message.
	if (!found) cout << "A student with the student ID: " << studentID << " does not exist in the Roster." << endl;
}

// Print All Students in Roster Function
// Return type: None
// The purpose of this function is to print out all the individual student's details from the Roster
void Roster::printAll() const
{
	// Loop through the entire Roster
	for (int i = 0; i < 5; ++i)
	{
		// If there are no more students to the Roster, break
		if (classRosterArray[i] == nullptr) break;

		// Otherwise, call the print method for each student
		classRosterArray[i]->print();
	}
}

// Print Average Days In Course Function
// Return type: None
// The purpose of this function is to find the student with the given student ID and calculate their average days in course and print it to the console.
void Roster::printAverageDaysInCourse(string studentID) const
{
	// Loop through the Roster
	for (int i = 0; i < 5; ++i)
	{
		// If the Roster is empty or the end of the Roster has been reached, break.
		if (classRosterArray[i] == nullptr) break;

		// Otherwise, find the student with the matching student ID
		if (classRosterArray[i]->GetStudentID() == studentID)
		{
			// Initialize a variable to store the sum.
			int sum = 0;
			int* daysInCourseArr = classRosterArray[i]->GetNumOfDaysToCompleteCourse();

			// Loop through the array of NumOfDaysToCompleteCourse
			for (int j = 0; j < 3; ++j)
			{
				sum += daysInCourseArr[j];
			}
			cout << setprecision(3);
			cout << "The student with the student ID of " << studentID << " has an Average Day to Complete Courses of "
				<< static_cast<double>(sum) / 3.0 << " days." << endl;
		}
	}
}

// Print Invalid Emails Function
// Return type: None
// The purpose of this function is to print all the emails that are invalid on the Roster
void Roster::printInvalidEmails() const
{
	string email = "";
	bool valid = true;

	// Loop through the enitre Roster and check individual student emails
	for (int i = 0; i < 5; ++i)
	{
		valid = true;
		email = classRosterArray[i]->GetEmailAddress();

		// Check if the email has any spaces
		if (email.find(' ') != -1) valid = false;

		// Check for '@' sign
		if (email.find('@') != -1)
		{
			// If found check if there is a period in the email that comes after the @ sign
			int index = email.find('@');

			// If no period is found
			if (email.substr(index, email.length() - index).find('.') == -1) valid = false;
		}
		else // If no '@' sign was found
		{
			valid = false;
		}

		// If the email was caught in any of the conditions of being invalid, print to the console
		if (!valid)
		{
			cout << "The student: " << classRosterArray[i]->GetFirstName() << " " << classRosterArray[i]->GetLastName() << " has an invalid Email Address of " << email << endl;
		}
	}
}

// Print STudents by DegreeProgram Function
// Return type: none
// This function will print the student with the given degree program to the console
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const
{
	int num = 1;

	// Loop through the class Roster
	for (int i = 0; i < 5; ++i)
	{
		// Check to make sure that the current slot isn't empty
		if (classRosterArray[i] != nullptr)
		{
			// Check the current student's degree program
			if (classRosterArray[i]->GetDegreeProgram() == degreeProgram)
			{
				cout << num << ". " << classRosterArray[i]->GetFirstName() << " " << classRosterArray[i]->GetLastName() << endl;
				num++;
			}
		}
	}
}

Student** Roster::GetClassRosterArray() const
{
	static Student* arr[5];

	// Store the classRosterArray 
	for (int i = 0; i < 5; ++i)
	{
		arr[i] = classRosterArray[i];
	}

	return arr;
}
