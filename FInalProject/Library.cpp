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
		cout << "2. Assign or return book" << endl;
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
			printAssignMenu();
			break;
		case 'B':
			break;
		case 'Q':
			exit(0);
		}
	}
}
void Library::showrecord()
{
	Record r;
	cout << "\t\t Book Taken by student" << endl;
	ifstream StdMgn;
	StdMgn.open("LibMng.dat", ios::in || ios::binary);
	while (StdMgn.read((char*)&r, sizeof(r)))
	{
		printf("%10s %10s %20s %30s %30s\n", "Student Id", "Book Id", "Book Title", "Issued Date","Return Date");
		printf("%10d %10d %20s %30s %30s\n", r.studentId,r.bookId,r.bookTitle, ctime(&r.issuedTime), ctime(&r.returnTime));
	}
}
/*
*return type void
*used to display the menu to assign return and show all the books
*/
void Library::printAssignMenu() {
	char choice='1';
	while (choice != 'B')
	{
		cout << "Enter your choice " << endl;
		cout << "1. To give book to student" << endl;
		cout << "2. To return a book" << endl;
		cout << "3. TO display all the book taken by student" << endl;
		cout << "B. to go back" << endl;
		cin >> choice;
		if (isalpha(choice) == true)
		{
			choice = toupper(choice);
		}
		switch (choice)
		{
		case'1':
			giveBook();
			break;
		case'2':
			returnbook();
			break;
		case '3':
			showrecord();
			break;
		case'B':
			break;
		default:
			cout << "Wrong choice" << endl;
		}
	}

}
/*
*return type void
*give a bbok to student account
*/
void Library::giveBook()
{
	Record r,g;
	int count=0;
	Student stud;
	Book book;
	time_t next;
	ifstream studentfile, bookfile;
	fstream StdBookFile;
	while (count != 1)
	{
		cout << "Enter Student Id:";
		cin >> r.studentId;
		studentfile.open("student.dat", ios::in || ios::binary);
		if (!studentfile)
			cerr << "Cannot read file" << endl;
		else {
			while (studentfile.read((char*)&stud, sizeof(stud)))
			{
				if (r.studentId == stud.getId())
				{
					count = 1;
					stud.PrintStudent();
				}
			}
		}
		if (count != 1)
			cout << "Sorry cannot find record " << endl;
		studentfile.close();
	}
	count = 0;
	while (count != 1)
	{
		cout << "Enter Book Id:";
		cin >> r.bookId;
		bookfile.open("Book.dat", ios::in || ios::binary);
		if (!bookfile) {
			cerr << "Cannot open file" << endl;
		}
		else
		{
			while (bookfile.read((char*)&book, sizeof(book)))
			{
				if (r.bookId == book.GetBookId())
				{
					count = 1;
					book.PrintBook();

					string title = book.GetBookTitle();
					std::size_t length = title.copy(r.bookTitle,20);
					r.bookTitle[length] = '\0';
					/*
				for (int i = 0; i < title.size(); i++)
					{
						r.bookTitle[i] = title[i];
					}
					*/
				}
			}
			if (count != 1)
				cout << "Cannot find the book id" << endl;
		}
		bookfile.close();
	}
	r.issuedTime = time(0);
	// Stack overflow helped us to get this code
	for (int i = 0; i < 14; ++i) {
		struct tm* tm = localtime(&r.issuedTime);
		tm->tm_mday += i;
		next = mktime(tm);
	}
	r.returnTime = next;
	count = 0;
	// reading to check if the record already exists
	StdBookFile.open("LibMng.dat", ios::in || ios::binary);
	if (!StdBookFile)
		cerr << "cannot read the file" << endl;
	else {
		while (StdBookFile.read((char*)&g, sizeof(g)))
		{
			if (g.studentId == r.studentId && g.bookId == r.bookId)
			{
				count = 1;
			}
		}
	}
	StdBookFile.close();
	if (count != 1)
	{
		// writing to the student file
		StdBookFile.open("LibMng.dat", ios::app);
		if (!StdBookFile)
		{
			cerr << "cannot find file" << endl;
		}
		else
		{
			if (book.EditQuantity(r.bookId) != true)
			{
				cout << "cannot give book to student as only 2 quantity is left" << endl;
			}
			else
			{
				StdBookFile.write((char*)&r, sizeof(r));
				cout << "Record added Successfully" << endl;
			}
		}
		
		StdBookFile.close();
	}
	else
		cout << "Sorry the book is already taken by the student" << endl;
	cin.get();
}
/*
*return type void 
*its called when a student return book
*/
void Library::returnbook()
{
	Record r, g;
	int count = 0, studentId, bookId;
	ifstream LibMgn;
	ofstream outFile;
	outFile.open("temp.dat", ios::out | ios::binary);
	while (count != 1)
	{
		cout << "Enter Student Id:";
		cin >> studentId;
		cout << "Enter Book Id:";
		cin >> bookId;
		LibMgn.open("LibMng.dat", ios::in || ios::binary);
		if (!LibMgn)
			cerr << "Cannot read file" << endl;
		else {
			while (LibMgn.read((char*)&r, sizeof(r)))
			{
				if (r.studentId != studentId && r.bookId != bookId)
				{
					count = 1;
					outFile.write((char*)&r, sizeof(r));
				}
			}

			LibMgn.close();
			outFile.close();
			remove("LibMng.dat");
			rename("temp.dat", "LibMng.dat");
			cout << "Record Deleted Sucessfully" << endl;
			if (count == 1)
				cout << "Sorry cannot find record " << endl;
			LibMgn.close();
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
	cout << "Enter your Library ID :";
	cin >> LibId;
	cin.ignore();
	cout << "Enter your Password :";
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
