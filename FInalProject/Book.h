#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<fstream>
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
	void PrintBook();
	void EditBook();
	void SearchBook();
	void Menu();
	int GetBookId();
	string GetBookTitle();
	void AddBook();
	void DeleteBook();
	void ShowBook();
	void EditQuantity(int n);
	virtual ~Book();
};

