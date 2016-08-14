#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include <time.h>
#include<ctime>
#include "Library.h"
#include <stdlib.h>     /* atoi */

/**
Author :Rutvik Patel,Himanshu Patel
Description: main Method of the program this is where the program starts execution
*/
/*
using namespace std;
int main()
{
	time_t base = time(0);
	for (int i = 0; i < 4; ++i) {
		struct tm* tm = localtime(&base);
		tm->tm_mday += i;
		time_t next = mktime(tm);
		std::cout << ctime(&next);
	}
	cin.get();

	return 0;
}
*/

void main()
{
	Library l;// Instance of librarty class
	char choice='1';// for user input
	cout << "Welcome" << endl; 
	while (choice !='Q')
	{
		cout << "1. Login" << endl;
		cout << "2. To add Librarian or student" << endl;
		cout << "Q. Exit" << endl;
		cin>>choice;
		switch(choice)
		{
		case '1':
			if (l.Login()==true) {
				l.Menu();
			}
			break;
		case '2':
			cout << "1. To add Librarian :" << endl;
			cout << "2. To add Student :" << endl;
			cin >> choice;
			switch (choice)
			{
			case '1':
				l.AddLibrary();
				break;
			case '2':
				Student s;
				s.AddStudent();
				break;
			}
			
			break;
		case 'Q':
			exit(0);
		default:
			cout << "Wrong Choice" << endl;
		}
	}
	cin.get();
}