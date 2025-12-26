#pragma once
#include<iostream>
using namespace std;

class Point
{
	private:
		float x, y;

	public:
		Point();
		Point(float, float);
		~Point();
		float getX()const;
		float getY()const;
		void input();
		void print();
};

