#pragma once
#include"Node.h"
class Edge
{
	private:
		Node u, v;
	public:
		Edge(Node, Node);
		Edge();
		Node getU() { return this->u; }
		Node getV() { return this->v; }
};

