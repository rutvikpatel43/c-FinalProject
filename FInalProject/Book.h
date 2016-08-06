#pragma once
#include<iostream>
#include<stdio.h>
using namespace std;
class Book
{
private:
	int BookId;
	char BookTitle[20];
	char BookISBN[20];
	int Quantity;
public:
	Book();
	int GetBookId();
	string GetBookTitle();
	void AddBook();
	void DeleteBook();
	void ShowBook();
	virtual ~Book();
};

