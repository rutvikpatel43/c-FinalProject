#pragma once

#include<iostream>
#include<stdio.h>
#include<fstream>
#include "Book.h"
#include "Student.h"
using namespace std;	
class Library
{
private:
	int LibrarianID;
	char LibrarianPassword[20];
public:
	Library();
	void Menu();
	bool Login();
	void AddLibrary();
	void UpdateLibrary();
	void DeleteLibrary();
	int GetLibraryId();
	string GetLibraryPass();
	~Library();
};

