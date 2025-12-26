#pragma once
#include"Point.h"
#include<math.h>
class Vector
{
private:
	float dx, dy;
public:
	Vector();
	Vector(float,float);
	~Vector();
	//getter setter
	float getDx()const;
	float getDy()const;
	void setDx(float);
	void setDy(float);
	Vector createVTCP(Point&,Point&);
	Vector createVTPT(const Vector&);
	double distance();
	double tichVoHuong(Vector);
	int viTriTuongDoi(Point&, Vector&, Point&, Point&);
};

