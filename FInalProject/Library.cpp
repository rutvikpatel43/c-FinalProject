#include "Library.h"

/*
* Authors : Rutvik Patel(#200305366), Himanshu Patel(#200306422)
* Description: Library definations file for Library class.
*/

/*
* return type void
* Add libraian to the libraian file
*/
void Library::AddLibrary()
{
	Library Lib;
	char username[20], password[20];
	ofstream LibraryFile;
	LibraryFile.open("Library.dat", ios::out);
	cin.ignore();
	cout << "Enter UserName for admin:";
	cin.getline(username, 20);
	cout << "Enter Passsword for Admin:";
	cin.getline(password, 20);

	if ((strcmp(username, "admin") == 0) && (strcmp(password, "admin") == 0))
	{
		if (!LibraryFile)
		{
			cerr << "Cannot open file" << endl;
		}
		else
		{
			cout << "Enter the new librarian Id:";
			cin >> Lib.LibrarianID;
			cout << "Enter the new Librarian Password :";
			cin >> Lib.LibrarianPassword;
			LibraryFile.write((char *)&Lib, sizeof(Lib));
			cout << "Record Added Sucessfully" << endl;
		}
	}
	else
	{
		cout << "Wrong Login" << endl;
	}
	LibraryFile.close();
}
/*
* return type void
* deletes Library from the Library file
*/
void Library::DeleteLibrary()
{

}
/*
* return type void
* updates libratian
*/
void Library::UpdateLibrary() {

}
Library::Library()
{
}
/*
* return type id
* returns id for the Library at the time of execution
*/
int Library::GetLibraryId()
{
	return LibrarianID;
}
/*
* return string type bool
* gets librarian password
*/
string Library::GetLibraryPass()
{
	string str="";
	int i = 0;
	while (LibrarianPassword[i] != ' ')
	{
		str = str + LibrarianPassword[i];
		i++;
	}
	return str;
}
/*
* return type void
* Menu for Librarian and can do all the things
*/
void Library::Menu()
{
	Book B;
	Student Std;
	char choice=' ';
	while (toupper(choice) != 'B')
	{
		//Print Menu
		cout << "Enter your choice" << endl;
		cout << "1. Book Managment" << endl;
		cout << "2. Assign book" << endl;
		cout << "Q to quit" << endl;
		cout << "B Back to Login Menu" << endl;
		cin >> choice;
		if(isalpha(choice))
		{ 
			choice = toupper(choice);
		}
		switch (choice)
		{
		case '1':
			B.Menu();
			break;
		case '2':
			break;
		case 'B':
			break;
		case 'Q':
			exit(0);
		}
	}
}
/*
* return type bool
* logins the librarian
*/
bool Library::Login()
{
	Library Lib;
	int LibId;
	char LibPass[20];
	ifstream LibraryFile;// Librarian file contains all the librarian
	LibraryFile.open("Library.dat", ios::in || ios::binary);
	//get the credintial from the user
	cout << "Enter your Library ID";
	cin >> LibId;
	cin.ignore();
	cout << "Enter your Password";
	cin.getline(LibPass,20);
	if (!LibraryFile)// trying to read the file
	{
		cerr << "Cannot Open File" << endl;
	}
	else
	{
		while (!LibraryFile.eof())
		{
			LibraryFile.read((char *)&Lib, sizeof(Lib));// record read and stored in lib
			if ((Lib.LibrarianID == LibId) && strcmp(Lib.LibrarianPassword, LibPass) == 0)
			{
				return true;
			}
		}
		// check if librarian exists
		// return true if exist else false
	}
	LibraryFile.close();
}
Library::~Library()
{
}
