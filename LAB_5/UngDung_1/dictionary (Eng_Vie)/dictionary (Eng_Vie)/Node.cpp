#include "Node.h"

Node::Node()
{

    //ctor
    this->key = "";
    this->meaning = "";
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->height = 0;
}
Node::Node(string w, string m) {
    //ctor
    this->key = w;
    this->meaning = m;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->height = 0;
}
Node::~Node()
{
    //dtor
}

