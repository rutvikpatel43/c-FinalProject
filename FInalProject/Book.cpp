#include "Book.h"

Book::Book()
{
}
int Book::GetBookId()
{
	return BookId;
}
string Book::GetBookTitle()
{
	string str = BookTitle;
	return str;
}
Book::~Book()
{
}
