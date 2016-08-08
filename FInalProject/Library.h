#pragma once

#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;	
class Library
{
private:
	int LibrarianID;
	char LibrarianPassword[20];
public:
	Library();
	bool Login();
	void AddLibrary();
	void UpdateLibrary();
	void DeleteLibrary();
	int GetLibraryId();
	string GetLibraryPass();
	~Library();
};

