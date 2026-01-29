///File: main.cpp

#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
    linkedlist* list_ = new linkedlist();
    element* e;
    e = new element(9);
    list_->InsertTail(e);
    e = new element(10);
    list_->InsertTail(e);
    e = new element(8);
    list_->InsertTail(e);
    list_->Traversal();
    list_->DeleteFirst();
    cout << "\n";
    list_->Traversal();
    return 0;
}

