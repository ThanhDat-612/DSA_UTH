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