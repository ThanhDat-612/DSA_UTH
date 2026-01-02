#include "SinglyLinkedList.h"
using namespace std;
linkedlist::linkedlist()
{
    //ctor
    this->head = nullptr;
    this->tail = nullptr;
    this->nNum = 0;
}

linkedlist::~linkedlist()
{
    //dtor
}
void linkedlist::InsertFirst(element* e) {
    if (this->head == nullptr)// Case 1
        this->head = this->tail = e;
    else {  // Case 2
        e->Setpointer(this->head); //step 1
        this->head = e;  // step 2
    }
    this->nNum++;

}
void linkedlist::InsertTail(element* e) {
    if (e == nullptr) return;
    e->Setpointer(nullptr);
    if (this->head == nullptr)
        this->head = this->tail = e;
    else {
        this->tail->Setpointer(e);// step 1
        this->tail = e;    // step 2
    }
    this->nNum++;
}
void linkedlist::Traversal() {
    element* p = this->head;
    while (p != nullptr) {
        cout << p->Getdata() << "\t";
        p = p->Getpointer();
    }
}
bool linkedlist::DeleteFirst() {
    if (this->head == nullptr) return false;
    else {
        element* p = this->head;
        this->head = this->head->Getpointer();
        delete p;
        return true;
    }
}

bool linkedlist::isEmpty() {
    return head == nullptr;
}

bool linkedlist::DeleteTail() {
    if (this->head == nullptr) return false;
    if (this->head == this->tail) { // Trường hợp chỉ có 1 phần tử
        delete this->head;
        this->head = this->tail = nullptr;
    }
    else {
        element* p = this->head;
        while (p->Getpointer() != this->tail) {
            p = p->Getpointer();
        }
        delete this->tail;
        this->tail = p;
        this->tail->Setpointer(nullptr);
    }
    this->nNum--;
    return true;
}
