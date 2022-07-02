<a name='Top'></a>
# Class Roster (School Project)

## Table of Contents
- [About this Project](#About)
  - [Project Scenario](#Scenario)
  - [Built With](#BuiltWith)
- [Usage](#Usage)
  - [Requirements](#Requirements)
- [The Program](#TheProgram)
  - [Classes](#Classes)
  - [Algorithms](#Algorithms)
- [Additional Information](#AddInfo)
<br>

<a name='About'></a>
## About this Project
This project was completed for my Scripting and Porgamming Applications course at WGU.

<a name='Scenario'></a>
### Project Scenario
The given scenario for the project:

_You are hired as a contractor to help a university migrate an existing student system to a new platform using C++ language. Since the application already exists, its requirements exist as well, and they are outlined in the next section. You are responsible for implementing the part of the system based on these requirements. A list of data is provided as part of these requirements. This part of the system is responsible for reading and manipulating the provided data._

_You must write a program containing two classes (i.e., Student and Roster). The program will maintain a current roster of students within a given course. Student data for the program include student ID, first name, last name, email address, age, an array of the number of days to complete each course, and degree program. This information can be found in the “studentData Table” below. The program will read a list of five students and use function calls to manipulate data (see part F4 in the requirements below). While parsing the list of data, the program should create student objects. The entire student list will be stored in one array of students called classRosterArray. Specific data-related output will be directed to the console._

<a name='BuiltWith'></a>
### Built With
This program was built using C++ with no additional imported libraries.
The project environment was on Windows 10 using Visual Studios Code.

<a name='Usage'></a>
## Usage
In order to run the program, you must have a GNU C++ Compiler (g++). Make sure the header and implementation files are in the same directory as main.cpp.

For Windows:

The easiest way to run this program on Windows is through Visual Studios Code or using a Linux Virtual Machine.

For Linux: 

Once all the files are in the same directory including the makefile, just run the make command in the terminal.

<a name='Requirements'></a>
### Requirements
Other than a C++ compiler, there are no specific requirements to run this program.

<a name='TheProgram'></a>
## The Program
The following steps describe what main.cpp should produce.
1. Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
2. Create an instance of the Roster class called classRoster.
3. Add each student to classRoster.
4. Convert the following pseudo code to complete the rest of the main() function:

    ```classRoster.printAll();
    classRoster.printInvalidEmails();

    //loop through classRosterArray and for each element:
    classRoster.printAverageDaysInCourse(/*current_object's student id*/);
    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");
    //expected: the above line should print a message saying such a student with this ID was not found.```

5. Implement the destructor to release the memory that was allocated dynamically in Roster.

<a name='Classes'></a>
### Classes
There are two classes for this program: Student and Roster.

**Student Class**

The Student object is responsible for representing each student by encapsulating the student's information. Below is the class UML Diagram.

![Image of the Student UML Diagram](https://github.com/verybigsnorlax/ClassRoster-SchoolProject/blob/5584631042cde3ad97c997a72084036488067d38/images/student_UML.png)

The Student Class contains basic attributes that describe the student such as their student ID, name, email, age, and degree program. For each attribute there is an accessor (getter) function and a mutator (setter) function.

There are two Student Class Constructors. The first one is a default constructor that initializes all attributes/variables and the second constructor is a parameterized constructor that takes in all the attributes as a paramter and initializes the attributes to the given values.

The final function included in the Student Class is a print function that prints the student's attributes in a specific format such as:

```
INPUT: 
int arr[] = {30, 35, 40};
student1 = Student("A1", "John", "Smith", "John1989@gmail.com", 20, arr, DegreeProgram::SECURITY);
student1.print();

OUTPUT:
Student ID: A1  First Name: John  Last Name: Smith  Email Address: John1989@gmail.com  Age: 20  Days in Course: {30, 35, 40}  Degree Program: Security
```

**Roster Class**

The Roster object is responsible for representing an entire Class Roster by holding an array of Student objects of students that are enrolled in the class.

![Image of the Roster UML Diagram](https://github.com/verybigsnorlax/ClassRoster-SchoolProject/blob/e9b15c7aad3ce9d95787e6f41531bb45743e6207/images/roster_UML.png)

The Roster Class contains one attribute which is a class roster array that holds Student objects.

There is one Roster Class Constructor and one Roster Class Destructor. The default constructor will set the class roster array to nullptrs and the destructor will deallocate the memory of the pointers before the program stops running.

Other methods consist of adding and removing Students along with printing all the Students and printing other things like the average days left in course, invalid emails, and printing Students of given degree programs.

<a name='Algorithms'></a>
### Algorithms
No specific algorithms were used for this program. This program mainly consisted of creating two Class definitions and implementing the accessor, mutator, and print methods defined in the classes.

<a name='AddInfo'></a>
## Additional Information
This project was required for my Scripting and Programming Applications Course at WGU

**Initiated** on March 14, 2021

**Completed** on March 17, 2021


[Back to the Top ↑↑↑↑↑](#Top)
