#pragma once
#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
class Student
{
	int StudentID;
	char StudentFirstName[20];
	char StudentLastName[20];
	int StudentCredit;
public:
	Student();
	int getId();
	void AddStudent();
	void UpdateStudent();
	void DeleteStudent();
	void PrintStudent();
	virtual ~Student();
};

