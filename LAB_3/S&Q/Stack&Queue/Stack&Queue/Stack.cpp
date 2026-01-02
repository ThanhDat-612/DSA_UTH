#include "Stack.h"

void Stack::push(int x) {
    element* p = new element(x);
    this->ll->InsertTail(p);
}
int Stack::pop() {
    if (this->isEmpty()) {
        cout << "STACK RONG, KHONG LAY DUOC PHAN TU";
        return -1;
    }
    int p = this->ll->Gettail()->Getdata();
    this->ll->DeleteTail();
    return p;
}
void Stack::printStack() {
    this->ll->Traversal();
}
Stack::Stack()
{
    //ctor
    this->nNum = 0;
    this->ll = new linkedlist();
}
Stack::~Stack()
{
    //dtor
}

bool Stack::isEmpty() {
    return ll->Gethead() == nullptr;
}
void Stack::pushPoint(Point p) {
    element* e = new element(p);
    this->ll->InsertTail(e);
}
Point Stack::popPoint() {
    if (this->ll->isEmpty()) {
        cout << "STACK RONG";
        return Point(-1, -1);
    }
    Point p = this->ll->Gethead()->GetPoint(); 
        this->ll->DeleteFirst(); 
        return p;
}
int Stack::top() {
    if (isEmpty()) return -1;
    return ll->Gettail()->Getdata();
}
int Stack::bot() {
    if (isEmpty()) return -1;
    return ll->Gethead()->Getdata();
}