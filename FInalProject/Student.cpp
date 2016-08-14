#include "Student.h"
/*
* Authors : Rutvik Patel(#200305366), Himanshu Patel(#200306422)
* Description: Book Defination file for book class.
*/

/**
* return type void
* addstudent adds student to the student list
*/
void Student::AddStudent()
{
	Student stud;
	ofstream file;
	cout << "Enter student ID: ";
	cin >> stud.StudentID;
	cin.ignore();
	cout << "Enter First name :";
	cin.getline(stud.StudentFirstName, 20);
	cout << "Enter Last name :";
	cin.getline(stud.StudentLastName, 20);
	stud.StudentCredit = 0;
	file.open("Student.dat", ios::app);
	file.write((char*)&stud, sizeof(stud));
	file.close();
}

/*
* return type void
* Description: deletes student from the student list
*/
void Student::DeleteStudent()
{

}
/*
* return type void
* updates student record
*/
void Student::UpdateStudent()
{

}
/*
* return type void will display all student details
* prints student on the screen
*/
void Student::PrintStudent()
{
	printf("%10s %20s %20s %10s\n", "Student Id", "First Name", "Last Name", "Credit");
	printf("%10d %20s %20s %10d\n", StudentID, StudentFirstName, StudentLastName, StudentCredit);
}
/*
*return type int for student id
*returns the id of the student 
*/
int Student::getId() {
	return StudentID;
}
/*
* Contructor for the class
*/
Student::Student()
{
}


Student::~Student()
{
}
