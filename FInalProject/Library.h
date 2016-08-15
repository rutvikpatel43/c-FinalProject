#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<ctime>
#include "Book.h"
#include "Student.h"
using namespace std;	
class Library
{
private:
	int LibrarianID;
	char LibrarianPassword[20];
	struct Record {
		int studentId;
		int bookId;
		char bookTitle[20];
		time_t issuedTime;
		time_t returnTime;
	};
public:
	Library();
	void showrecord();
	void printAssignMenu();
	void Menu();
	bool Login();
	void AddLibrary();
	void UpdateLibrary();
	void DeleteLibrary();
	int GetLibraryId();
	void giveBook();
	void returnbook();
	string GetLibraryPass();
	~Library();
};

