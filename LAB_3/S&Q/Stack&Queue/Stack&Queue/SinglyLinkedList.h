#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "element.h"
#include<iostream>
class linkedlist
{
private:
    element* head;
    element* tail;
    int nNum;
public:
    linkedlist();
    virtual ~linkedlist();
    element* Gethead() { return head; }
    void Sethead(element* val) { head = val; }
    element* Gettail() { return tail; }
    void Settail(element* val) { tail = val; }
    void InsertFirst(element*);
    virtual void InsertTail(element*);
    bool DeleteFirst();
    void Traversal();
    bool DeleteTail();
    bool isEmpty();

protected:


};

#endif // LINKEDLIST_H
