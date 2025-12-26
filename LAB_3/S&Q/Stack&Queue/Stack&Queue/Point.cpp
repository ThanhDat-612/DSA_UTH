#include "Point.h"
Point::Point() {
	x = 0;
	y = 0;
}
Point::Point(int a, int b) {
	x = a;
	y = b;
}
Point::~Point() {

}
//getter setter
int Point::getX() {
	return  this->x;
}
int Point::getY() {
	return this->y;
}
void Point::setX(int n) {
	x = n;
}
void Point::setY(int n) {
	y = n;
}