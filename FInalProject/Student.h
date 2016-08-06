#pragma once
class Student
{
	int StudentID;
	char StudentFirstName[20];
	char StudentLastName[20];
	int StudentCredit;
public:
	Student();
	void AddStudent();
	void UpdateStudent();
	void DeleteStudent();
	void PrintStudent();
	virtual ~Student();
};

