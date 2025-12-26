#include "Point.h"

Point::Point() {
	this->x = 0;
	this->y = 0;
}
Point::Point(float x, float y) {
	this->x = x;
	this->y = y;
}
Point::~Point() {
}

float Point::getX() const {
	return this->x;
}
float Point::getY() const {
	return this->y;
}
void Point::input() {
	cin >> x >> y;
}
void Point::print() {
	cout << "(" << x << "," << y << ")" << endl;
}