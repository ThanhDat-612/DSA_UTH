#pragma once
#include"Element.h"

class DaThuc
{
	private:
		element* head;
		element* tail;
		
	public:
		DaThuc();
		~DaThuc();

		void print();
		void insertElement(element*);
		void insertTail(element* );
		void insertFirst(element*);
		double result(double x);
		DaThuc operator+(const DaThuc&);
		DaThuc operator*(const DaThuc& );
};

