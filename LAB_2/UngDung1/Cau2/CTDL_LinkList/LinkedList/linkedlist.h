#pragma once
#include "element.h"
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
    void InsertTail(element*);
    bool DeleteFirst();
    void Traversal();
    void removeAll();
    long long sumList();
    element* maxList();  // return element
    int countPrime();
    void insertTail(element*);
    void InsertAfter(element* ,element*);
    bool DeleteTail();
    bool DeleteElm(element* );
    int countEle(element*);
    bool exists(element*);
    void split(linkedlist* , linkedlist* , element* );
protected:

};

