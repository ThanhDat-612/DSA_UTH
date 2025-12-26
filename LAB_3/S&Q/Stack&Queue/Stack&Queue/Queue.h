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
		void enqueue(Point);

		int dequeue();
		void printQueue();

};

