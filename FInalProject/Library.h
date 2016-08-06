#pragma once
class Library
{
private:
	int LibrarianID;
	char LibrarianPassword[20];
public:
	Library();
	void AddLibrary();
	void UpdateLibrary();
	void DeleteLibrary();
	int GetLibraryId();
	~Library();
};

