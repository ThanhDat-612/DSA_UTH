#include "Node.h"

Node::Node(element id) {
	this->id = id;
}
Node::Node() {
	this->id = 0;
}
int Node::getId() {
	return this->id.Getdata();
}

