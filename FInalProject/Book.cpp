#include "Book.h"
/*
* Authors : Rutvik Patel(#200305366), Himanshu Patel(#200306422)
* Description: Book Defination file for book class.
*/

/*
* Book()- Constructor for book class
* Description: Intializes value to the object of class.
*/
Book::Book()
{

}
/*
* return type int
* GetBookId() returns the book id of the current object
* Description: returns the book id so that it can be used to write in library record.
*/
int Book::GetBookId()
{
	return BookId;
}
/*
* return type is string
* GetBookTitle()
* Description: returns the title of the book.
*/
string Book::GetBookTitle()
{
	string str = BookTitle;
	return str;
}
/*
* return type is void 
* will add book to the record
*/
void Book::AddBook()
{
	Book B;
	ofstream BookFile;
	BookFile.open("Book.dat", ios::app);
	cout << "Enter Book ID:";
	cin >> B.BookId;
	cout << "Enter Book Title:";
	cin >> B.BookTitle;
	cin.ignore();
	cout << "Enter Book ISBN:";
	cin >> B.BookISBN;
	cout << "Enter the quantity:";
	cin >> B.Quantity;
	if (!BookFile)
	{
		cerr << "Cannot Open File" << endl;
	}
	else
	{
		BookFile.write((char*)&B, sizeof(B));
		cout << "Record Added Sucessfully" << endl;
	}
}
/*
* return type void
* Deletes book from the book file
*/
void Book::DeleteBook()
{
	int n;
	cout << "Enter Book Id to Delete" << endl;
	cin >> n;
	Book obj;
	ifstream inFile;
	inFile.open("Book.dat", ios::binary);
	ofstream outFile;
	outFile.open("temp.dat", ios::out | ios::binary);
	while (inFile.read((char*)&obj, sizeof(obj)))
	{ 
		if (obj.BookId != n)
		{
			outFile.write((char*)&obj, sizeof(obj));
		} 
	}
	inFile.close();
	outFile.close();
	remove("Book.dat");
	rename("temp.dat", "Book.dat");
	cout << "Record Deleted Sucessfully" << endl;
}

void Book::PrintBook()
{
	printf("%10s %20s %20s %10s\n", "Book Id", "Book Title", "Book ISBN", "Qunatity");
	printf("%10d %20s %20s %10d\n",BookId,BookTitle, BookISBN, Quantity);
}

/*
* return type void
* shows the book from the file
*/
void Book::ShowBook()
{
	Book obj;
	ifstream inFile;
	cout << "\t\t\tBook Details:\n";
	printf("%10s %10s %10s %10s\n", "Book Id", "Book Title", "Book ISBN", "Quantity");
	inFile.open("Book.dat", ios::in|| ios::binary);
	while (inFile.read((char*)&obj, sizeof(obj)))
	{
			printf("%10d %10s %10s %10d\n", obj.BookId,obj.BookTitle,obj.BookISBN,obj.Quantity);
	}
	inFile.close();
}

/***
*Return type void
*Description: to give crud option for book class
**/
void Book::Menu()
{
	char choice = ' ';
	while (toupper(choice)!='B')
	{
		// Menu Print
		cout << "1. Add Book" << endl;
		cout << "2. Delete book" << endl;
		cout << "3. Edit book" << endl;
		cout << "4. Display all books" << endl;
		cout << "5. Search Book" << endl;
		cout << "B Back to Librarian Menu" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':
			AddBook();
			break;
		case '2':
			DeleteBook();
			break;
		case '3':
			EditBook();
			break;
		case '4':
			ShowBook();
			break;
		case '5':
			SearchBook();
		default:
			break;
		}
	}
}
/*
* Return type void
* description to edit book details
*/
void Book::EditBook() {
	int n;
	cout << "Enter Book Id to Edit:" << endl;
	cin >> n;
	Book obj;
	ifstream inFile;
	inFile.open("Book.dat", ios::binary);
	ofstream outFile;
	outFile.open("temp.dat", ios::out | ios::binary);
	while (inFile.read((char*)&obj, sizeof(obj)))
	{
		if (obj.BookId == n)
		{
			obj.BookId = n;
			cout << "Enter Book Title" << endl;
			cin >> obj.BookTitle;
			cout << "Enter Book ISBN:" << endl;
			cin >> obj.BookISBN;
			outFile.write((char*)&obj, sizeof(obj));
		}
		else {
			outFile.write((char*)&obj, sizeof(obj));
		}
	}
	inFile.close();
	outFile.close();
	remove("Book.dat");
	rename("temp.dat", "Book.dat");
	cout << "Record Updated Sucessfully" << endl;

}
/*
* Return type void
* description to Search book details
*/
void Book::SearchBook()
{
	int id;
	Book obj;
	ifstream file;
	cout << "Enter the Book Id you want to search";
	cin >> id;
	file.open("Book.dat", ios::in || ios::binary);
	if (!file)
	{
		cerr << "Cannot open file";
	}
	else
	{
		while (file.read((char*)&obj, sizeof(obj)))
		{
			if (obj.BookId == id)
			{
				printf("%10s %10s %10s %10s\n", "Book Id", "Book Title", "Book ISBN", "Quantity");
				printf("%10d %10s %10s %10d\n", obj.BookId, obj.BookTitle, obj.BookISBN, obj.Quantity);
			}
			
		}
		
	}
}
Book::~Book()
{
}
