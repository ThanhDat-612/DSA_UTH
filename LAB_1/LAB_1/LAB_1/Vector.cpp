#include "Vector.h"

Vector::Vector() {
	dx = 0;
	dy = 0;
}
Vector::Vector(float dx, float dy) {
	this->dx = dx;
	this->dy = dy;
}
Vector::~Vector() {

}

float Vector::getDx()const {
	return this->dx;
}
float Vector::getDy()const {
	return this->dy;
}
void Vector::setDx(float newDx) {
	this->dx = newDx;
}
void Vector::setDy(float newDy) {
	this->dy = newDy;
}
Vector Vector::createVTCP(Point& A, Point& B) {
	Vector AB;
	AB.dx = B.getX() - A.getX();
	AB.dy = B.getY() - A.getY();
	return AB;
}
Vector Vector::createVTPT(const Vector& v) {
	Vector n;
	n.dx = -v.dy;
	n.dy = v.dx;
	return n;
}
double Vector::distance() {
	return sqrt(this->dx * this->dx + this->dy * this->dy);
}

double Vector::tichVoHuong(Vector v) {
	return this->dx * v.dx + this->dy*v.dy;
}

int Vector::viTriTuongDoi(Point& A, Vector& AB, Point& P, Point& Q) {
	Vector nAB = createVTPT(AB);
	Vector AP = Vector(P.getX() - A.getX(), P.getY() - A.getY());
	Vector AQ = Vector(Q.getX() - A.getX(), Q.getY() - A.getY());

	double sP = nAB.tichVoHuong(AP);
	double sQ = nAB.tichVoHuong(AQ);
	if (sP == 0 || sQ == 0) {
		return 0;//nam tren dt
	}
	else if (sP * sQ > 0) {
		return 1; //cungphia
	}
	return -1; // khacphia
}
