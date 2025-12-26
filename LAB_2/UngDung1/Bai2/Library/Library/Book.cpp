#include "Book.h"

Book::Book() {
	bookName = "";
	numAu = 0;
	year = 1000;
	pointer = nullptr;
}
Book::~Book() {

}
string& Book::getBookName() {
	return this->bookName;
}
int& Book::getNumAu() {
	return this->numAu;
}
string& Book::getAuthor(int index) {
	return this->author[index];
}
string& Book::getPublisher() {
	return this->publisher;
}
int& Book::getYear() {
	return this->year;
}
Book* Book::getPointer() {
	return pointer;
}
void Book::setPointer(Book* b) {
	pointer = b;
}

void Book::setNumAu(int num) {
	numAu = num;
}
void Book::setPublisher(string p) {
	publisher = p;
}
void Book::setYear(int y) {
	year = y;
}
void Book::setAuthor(int index, string n) {
	author[index] = n;
}
//Book* Book::createBook() {
//	Book* b = new Book();
//	cout << "Name: ";
//	getline(cin, b->getBookName());
//	cout << "Num of Authors: ";
//	cin >> b->getNumAu();
//	cin.ignore();
//	for (int i = 0;i < b->getNumAu();i++) {
//		cout << "Author[" << i + 1 << "]: ";
//		getline(cin, b->getAuthor(i));
//	}
//	cout << "Publisher: ";
//	getline(cin, b->getPublisher());
//	cout << "Published in: ";
//	cin >> b->year;
//	cin.ignore();
//	return b;
//}