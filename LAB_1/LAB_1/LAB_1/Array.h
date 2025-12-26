#pragma once
#include<iostream>
using namespace std;

class Array
{
	private:
		int* data;
		int size;
	public:
		Array(int n);
		Array(const Array& other);
		~Array();
		void input();
		void print();
		int countElm();
		void swap(int& ,int&);
		void sort(bool);
};

