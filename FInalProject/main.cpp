#include<iostream>
#include<stdio.h>
#include "Library.h"
#include <stdlib.h>     /* atoi */

/**
Author :Rutvik Patel,Himanshu Patel
Description: main Method of the program this is where the program starts execution
*/
using namespace std;
void main()
{
	Library l;// Instance of librarty class
	char choice='1';// for user input
	cout << "Welcome" << endl; 
	while (choice !='Q')
	{
		cout << "1. Login" << endl;
		cout << "2. To add Librarian" << endl;
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
			l.AddLibrary();
			break;
		case 'Q':
			exit(0);
		default:
			cout << "Wrong Choice" << endl;
		}
	}
	cin.get();
}