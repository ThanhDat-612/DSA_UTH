#include "element.h"

element::element()
{
    //ctor
    this->data = 0;
    this->pointer = nullptr;
}
element::element(int data)
{
    //ctor
    this->data = data;
    this->pointer = nullptr;
}

element::~element()
{
    //dtor
}
element::element(Point p) {
    this->p = p;
    this->pointer = nullptr;
}