#pragma once
#include"SinglyLinkedList.h"
#include<iostream>
using namespace std;
class Queue
{
	private:
		int nNum;
		linkedlist* ll;
	public:
		Queue();
		virtual ~Queue();
		void enqueue(int);
		void enqueuePoint(Point);
		Point dequeuePoint();
		int dequeue();
		void printQueue();
		bool isEmpty();

};

