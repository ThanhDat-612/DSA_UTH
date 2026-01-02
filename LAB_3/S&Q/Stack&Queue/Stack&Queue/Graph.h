#pragma once
#include"SinglyLinkedList.h"
#include"Edge.h"
#include"Stack.h"
#include"Queue.h"

using namespace std;
class Graph
{
	private:
		int numNodes;
		linkedlist** adj;
	public:
		Graph(int);
		void addEdge(Edge);
		int getNumNodes();
		void printGraph();
		void BFS(int startNode);
		void DFS(int startNode);
};

