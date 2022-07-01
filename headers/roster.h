#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

class Roster
{
	public:
		// Constructor
		Roster();
		// Destructor
		~Roster();

		// Roster functions
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
		void remove(string studentID);
		void printAll() const;
		void printAverageDaysInCourse(string studentID) const;
		void printInvalidEmails() const;
		void printByDegreeProgram(DegreeProgram degreeProgram) const;
		
		// Accessor Function
		Student** GetClassRosterArray() const;

	private:

		// Roster Class Attributes
		Student* classRosterArray[5];
};

#endif