#pragma once
class Point
{
	private:
		int x, y;
	public:
		Point();
		Point(int, int);
		~Point();
		//getter setter
		int getX();
		int getY();
		void setX(int);
		void setY(int);
};

