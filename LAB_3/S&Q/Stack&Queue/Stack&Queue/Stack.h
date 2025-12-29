#ifndef STACK_H
#define STACK_H
#include "SinglyLinkedList.h"
#include<iostream>
using namespace std;
class Stack
{
private: int nNum;
       linkedlist* ll;
public:
    Stack();
    virtual ~Stack();
    void push(int);
    void  pushPoint(Point);
    Point popPoint();
    int pop();
    void printStack();
    bool isEmpty();
    int top();//phan tu cuoi cung
    int bot();//phan tu dau tien
};

#endif // STACK_H
