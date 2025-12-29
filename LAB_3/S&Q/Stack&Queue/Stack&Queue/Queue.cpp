#include "Queue.h"

void Queue::enqueue(int x) {
    element* p = new element(x);
    this->ll->InsertTail(p);
}
int Queue::dequeue() {
    if (ll->isEmpty()) {
        cout << "QUEUE RONG, KHONG LAY DUOC PHAN TU";
        return -1;
    }
    int p = this->ll->Gethead()->Getdata();
    this->ll->DeleteFirst();
    return p;

}
void Queue::printQueue() {
    this->ll->Traversal();
}
Queue::Queue()
{
    //ctor
    this->nNum = 0;
    this->ll = new linkedlist();
}
Queue::~Queue()
{
    //dtor
}
bool Queue::isEmpty() {
    return this->ll->Gethead() == nullptr;
}

void Queue::enqueuePoint(Point p) {
    element* e = new element(p);
    this->ll->InsertTail(e);
}

Point Queue::dequeuePoint() {
    if (ll->isEmpty()) {
        cout << "Queue Rong";
        return Point(-1, -1);
    }
    Point p = this->ll->Gethead()->GetPoint();
    this->ll->DeleteFirst();
    return p;
}
int Queue::front() {
    if (isEmpty()) return -1;
    return ll->Gethead()->Getdata();
}
int Queue::last(){
    if (isEmpty()) return -1;
    return ll->Gettail()->Getdata();
}