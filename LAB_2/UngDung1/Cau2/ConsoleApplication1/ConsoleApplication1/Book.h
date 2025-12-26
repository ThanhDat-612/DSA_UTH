#pragma once
#include<iostream>
#include<string>
using namespace std;

class Book
{
private:
	string bookName;
	int numAu;
	string author[5];
	string publisher;
	int year;
	Book* pointer;
public:
	Book();
	~Book();
	//getter setter

	string& getBookName();
	void setBookName(string);

	int& getNumAu();
	void setNumAu(int);

	string& getAuthor(int index);
	void setAuthor(int, string);

	string& getPublisher();
	void setPublisher(string);

	int& getYear();
	void setYear(int);

	Book* getPointer();
	void setPointer(Book*);

	//Book* createBook();
};

