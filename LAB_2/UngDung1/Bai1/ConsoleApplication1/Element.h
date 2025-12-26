#pragma once
#include<iostream>
using namespace std;

class element {
	private:
		int coSo;
		int soMu;
		element* pointer;
	public:
		element(int c=0, int s=0);
		element();
		//getter setter
		int getCoSo() { return coSo; };
		void setCoSo(int);
		int getSoMu() { return soMu; };
		void setSoMu(int );

		element* getPointer();
		void setPointer(element* val);
};