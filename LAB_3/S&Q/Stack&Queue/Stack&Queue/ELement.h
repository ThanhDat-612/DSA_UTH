/// File: element.h 
#ifndef ELEMENT_H
#define ELEMENT_H
#include"Point.h"

class element
{
private:
    int data;
    element* pointer;
    Point p;

public:
    element();
    element(int);
    element(Point);
    virtual ~element();

    int Getdata() { return data; }
    void Setdata(int val) { data = val; }
    element* Getpointer() { return pointer; }
    void Setpointer(element* val) { pointer = val; }
    Point GetPoint() { return p; }
    void SetPoint(Point val) { p = val; }
protected:

};

#endif // ELEMENT_H
