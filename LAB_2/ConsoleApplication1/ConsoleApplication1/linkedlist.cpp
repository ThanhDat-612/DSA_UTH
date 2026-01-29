#include "linkedlist.h"
#include <iostream>
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
//void linkedlist::InsertFirst(element * e) {
//    if (this->head == nullptr)// Case 1
//        this->head = this->tail = e;
//    else {  // Case 2
//        e->Setpointer(this->head); //step 1
//        this->head = e;  // step 2
//    }
//    this->nNum++;
//
//}
//void linkedlist::InsertTail(element * e) {
//    if (this->head == nullptr)
//        this->head = this->tail = e;
//    else {
//        this->tail->Setpointer(e);// step 1
//        this->tail = e;    // step 2
//    }
//    this->nNum++;
//}
void linkedlist::InsertAfter(int index, element* e) {
    if (this->head == nullptr) this->head = this->tail = e;
    else {
        element* p = this->head;
        int count = 0;
        while (p != nullptr && count < index) {
            p = p->Getpointer();
            count++;
        }
        if (p == nullptr) {
            cout << "Error Index" << endl;
            return;
        }
        e->Setpointer(p->Getpointer());
        p->Setpointer(e);
        if (p == tail) {
            tail = e;
        }
    }
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

void linkedlist::removeAll() {
    element * p = this->head;
    element * q;
    while (p != nullptr) {
        q = p;
        p = p->Getpointer();
    delete q;       
    }
    this->head = nullptr;
    this->tail = nullptr; 
}

long long linkedlist::sumList() {
    long long sum = 0;
    element * p = this->head;
    while (p != nullptr) {
        sum += p->Getdata();
        p = p->Getpointer();
    }
    return sum;
}
element* linkedlist::maxList() {
    if (this->head == nullptr) {
        cout << "Empty";
        return 0;
    }
    element* max = this->head;
    element* p = this->head->Getpointer();
    while (p != nullptr) {
        if (p->Getdata() > max->Getdata()) {
            max->Setdata(p->Getdata());
        }
        p = p->Getpointer();
    }
    return max;
}

int linkedlist::countPrime() {
    int count = 0;
    if (this->head == nullptr) return 0;

    element* p = this->head;
    while (p != nullptr) {
        int n = p->Getdata();
        bool flag = true;

        if (n < 2) flag = false;
        else if (n == 2) flag = true;
        else if (n % 2 == 0) flag = false;
        else {
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) count++;
        p = p->Getpointer();
    }

    return count;
}

bool linkedlist::DeleteTail() {
    if (this->head == nullptr) return false;
    else {
        element * p = this->head;
        while (p->Getpointer() != tail) {
            p = p->Getpointer();
        }
        element * temp = tail;
        tail = p;
        tail->Setpointer(nullptr);
        delete temp;
        return true;
    }
}
bool linkedlist::DeleteElm(element* e) {
    if (this->head == nullptr) return false;
    if (head == e) {
        head = head->Getpointer();
        if (head == nullptr) tail = nullptr; // nếu list chỉ có 1 node
        delete e;
        return true;
    }else {
        element * p = this->head;
        while (p->Getpointer() && p->Getpointer() != e) {
            p = p->Getpointer();
        }
        if (p->Getpointer() == nullptr) return false;
        if (e == tail) {
            tail = p;
            p->Setpointer(nullptr);
        }else {
            p->Setpointer(e->Getpointer());
        }
        delete(e);
        return true;
    }
}
int linkedlist::countEle(element* e) {
    if (this->head == nullptr) return 0;
    element* p = this->head;
    int count = 0;
    while (p != nullptr) {
        if (p->Getdata() == e->Getdata()) {
            count++;
        }
        p = p->Getpointer();
    }
    return count;
}

bool linkedlist::exists(element* e) {
    if (countEle(e) == 0) return false;
    return true;
}

void linkedlist::InsertFirst(element* e) {
    if (this->head == nullptr)// Case 1
        this->head = this->tail = e;
    else {  // Case 2
        if (exists(e)) {
            cout << "Already have element!" << endl;
            delete e;
            return;
        }
        e->Setpointer(this->head); //step 1
        this->head = e;  // step 2
    }
    this->nNum++;

}
void linkedlist::InsertTail(element* e) {
    if (this->head == nullptr)
        this->head = this->tail = e;
    else {
        if (exists(e)) {
            cout << "Already have element!" << endl;
            delete e;
            return;
        }
        this->tail->Setpointer(e);// step 1
        this->tail = e;    // step 2
    }
    this->nNum++;
}
void linkedlist::split(linkedlist* l1, linkedlist* l2, element* e) {
    element* p = this->head;
    while (p != nullptr) {
        element x = p->Getdata();
        if (x.Getdata() < e->Getdata()) {
            l1->InsertTail(new element(x));
        }
        else if (x.Getdata() > e->Getdata()) {
            l2->InsertTail(new element(x));
        }
        p = p->Getpointer();
    }
}
