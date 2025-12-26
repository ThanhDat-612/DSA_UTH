#pragma once
#include "Book.h"

class BookLinkedList
{
private:
	Book* head;
	Book* tail;
public:

	BookLinkedList();

	void insertTail(Book*);
	void inputList();
	int countByAuthor(string);
	void searchByYear(int, string);
};

