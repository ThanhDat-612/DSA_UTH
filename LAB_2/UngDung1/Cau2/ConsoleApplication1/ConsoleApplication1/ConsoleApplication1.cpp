#include<iostream>
#include"BookLinkedList.h"
using namespace std;

int main() {
	BookLinkedList list;
	list.inputList();
	cout << endl;

	string author;
	cout << "Nhap tac gia: ";
	getline(cin, author);
	cout << "So sach cua tac gia " << author << "la " << list.countByAuthor(author);

	int year;
	string b;
	cout << "Nhap nam xuat ban: ";
	cin >> year;
	cin.ignore();
	cout << "Nhap nha xuat ban: ";
	getline(cin, b);
	cout << "List sach";
	list.searchByYear(year,b);
	cout << "done";
}