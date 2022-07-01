#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "student.h"
#include "roster.h"
#include "degree.h"
using namespace std;

int main()
{
	// Print out my information
	cout << "Course Title: C867 Scripting and Programming" << endl
		<< "Programming Language Used: C++" << endl
		<< "WGU Student ID: ---------" << endl
		<< "Name: Brian Kim" << endl;
	cout << "********Begin Program********" << endl << endl;

	// Declare and initiate student data from the student data table
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Brian,Kim,email@school.edu,19,30,40,28,SOFTWARE"
	};

	// Instantiate a Roster object
	Roster classRoster;

	// Declare and initialize necessary variables
	string line = "";
	string data = "";
	vector<string> vec;
	stringstream ss;
	
	string studentID = "";
	string firstName = "";
	string lastName = "";
	string emailAddress = "";
	int age = 0;
	int dayInCourse1 = 0;
	int dayInCourse2 = 0;
	int dayInCourse3 = 0;
	DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;

	// Parse the data and add each student details as a student to the Roster
	for (int i = 0; i < 5; ++i)
	{
		// Store the line of student data into line
		line = studentData[i];
		ss << line;
		
		// Grab each individual student data, separating them by each comma
		while (getline(ss, data, ','))
		{
			// Store the data into the vector to be able to access it later
			vec.push_back(data);
		}

		// Assign the data from the vector to the matching variables
		studentID = vec[0];
		firstName = vec[1];
		lastName = vec[2];
		emailAddress = vec[3];
		age = stoi(vec[4]);
		dayInCourse1 = stoi(vec[5]);
		dayInCourse2 = stoi(vec[6]);
		dayInCourse3 = stoi(vec[7]);
		
		if (vec[8] == "SECURITY") degreeProgram = DegreeProgram::SECURITY;
		else if (vec[8] == "NETWORK") degreeProgram = DegreeProgram::NETWORK;
		else if (vec[8] == "SOFTWARE") degreeProgram = DegreeProgram::SOFTWARE;

		// Add student to Roster
		classRoster.add(studentID, firstName, lastName, emailAddress, age, dayInCourse1, dayInCourse2, dayInCourse3, degreeProgram);

		// CLear vector and stringstream
		vec.clear();
		ss.clear();
		data = "";
	}

	
	// Now that each student is added to the Roster, print all the students on the Roster
	cout << "-------Class Roster-------" << endl;
	
	classRoster.printAll();
	
	// Print all the invalid emails to the console
	cout << endl << endl;
	cout << "-------Invalid Emails-------" << endl;
	
	classRoster.printInvalidEmails();

	// Loop through classRosterArray and for each element print the Average days in Course
	cout << endl << endl;
	cout << "-------Average Days In Course-------" << endl;
	
	Student** classRosterArray = classRoster.GetClassRosterArray();
	
	for (int i = 0; i < 5; ++i)
	{
		// Check to make sure that the slot isnt empty
		if (classRosterArray[i] != nullptr)
		{
			classRoster.printAverageDaysInCourse(classRosterArray[i]->GetStudentID());
		}
	}

	// Print the students by the category of their degree
	cout << endl << endl;
	cout << "-------Students in Software Degree Program-------" << endl;

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	// Remove Student A3 and then Print the Roster again
	cout << endl << endl;
	cout << "-------Remove Student A3-------" << endl;

	classRoster.remove("A3");
	classRoster.printAll();

	// Try removing Student A3 again. Should print an error message
	cout << endl << endl;
	cout << "-------Try Removing Student A3 Again-------" << endl;

	classRoster.remove("A3");

	return 0;
}