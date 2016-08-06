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

}
/*
* return type void
* Deletes book from the book file
*/
void Book::DeleteBook()
{

}
/*
* return type void
* shows the book from the file
*/
void Book::ShowBook()
{

}
Book::~Book()
{
}
