#pragma once
class Librarian
{
private:
	int LibrarianID;
	char LibrarianPassword[20];
public:
	Librarian();
	void AddLibrarian();
	void UpdateLibrarian();
	void DeleteLibrarian();
	int GetLibrarianId();
	~Librarian();
};

