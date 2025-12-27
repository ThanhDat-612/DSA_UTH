#pragma once
#include"Point.h"
#include<iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class Matrix
{
	private:
		int rows, cols;
		int** data;
	public:
		Matrix(int , int );
		~Matrix();

		void setElement(int, int, int);
		int getElement(int,int);
		bool isValid(Point);

		int getRows() { return rows; }
		int getCols() { return cols; }
		void printMatrix();
		void generateRandom(float obstacleDensity);
};

