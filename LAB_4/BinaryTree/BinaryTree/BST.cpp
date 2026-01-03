#include "BST.h"
#include <iostream>

using namespace std;
BST::BST()
{
    //ctor
    this->root = nullptr;
}

BST::~BST()
{
    //dtor
}
bool BST::InsertNode(Node* n) {
    Node* p = this->root;
    Node* T=nullptr;
    if (root == nullptr)
    {
        this->root = n;
        return true;
    }
    while (p != nullptr) {
        T = p;

        if (p->Getkey() > n->Getkey())
            p = p->Getleft();
        else
            if (p->Getkey() < n->Getkey())
                p = p->Getright();
            else
                if (p->Getkey() == n->Getkey())
                    return false;
    }

    if (T->Getkey() > n->Getkey())
        T->Setleft(n);
    else T->Setright(n);

    n->Setparent(T);
    return true;

}
bool BST::InsertNodeRe(Node* root, Node* p) {
    if (root == nullptr) {
        root = p;
        return true;
    }
    if (root->Getkey() == p->Getkey())
        return false;
    else if (root->Getkey() > p->Getkey())
        return InsertNodeRe(root->Getleft(), p);
    else return InsertNodeRe(root->Getright(), p);
}
// tien to 
void BST::NLR(Node* r) {
    if (r != nullptr) {
        cout << r->Getkey() << "\n";
        NLR(r->Getleft());
        NLR(r->Getright());
    }
}
// trung to
// be den lon 
void BST::LNR(Node* r) {
    if (r != nullptr) {
        LNR(r->Getleft());
        cout << r->Getkey() << "\n";
        LNR(r->Getright());
    }
}
// hau to
void BST::LRN(Node* r) {
    if (r != nullptr) {
        LRN(r->Getleft());
        LRN(r->Getright());
        cout << r->Getkey() << "\n";
    }
}
void BST::TravelNLR() {
    NLR(this->root);
}
void BST::TravelLNR() {
    LNR(this->root);
}
void BST::TravelLRN() {
    LRN(this->root);
}
Node* BST::search_x(int k) {
    Node* p = this->root;
    while (p != nullptr) {
        if (k == p->Getkey())
            return p;
        if (k < p->Getkey())
            p = p->Getleft();
        else
            p = p->Getright();
    }
    return nullptr;
}

/// <howToDo>
/// Đi hết nhánh trái ở bên phải
/// HOẶC
/// Đi hết nhánh phải ở bên trái
/// </howToDo>

void BST::deleteNode(Node* n) {
    if (n == nullptr) return;
    Node* p = n;
    // xoa la'
    if (n->Getleft() == nullptr && n->Getright() == nullptr) {
        // sinh vien code
        Node* parent = n->Getparent();
        if (parent == nullptr) {
            this->root = nullptr;
        }
        else {
            if (parent->Getleft() == n) parent->Setleft(nullptr);
            else if (parent->Getright() == n) parent->Setright(nullptr);
        }
        delete n;
    }
    // xoa node co con
    else {
        if (p->Getright() != nullptr) {
            p = p->Getright();
            while (p->Getleft() != nullptr)
                p = p->Getleft();
            n->Setkey(p->Getkey());
            deleteNode(p);
        }
        else {
            p = p->Getleft();
            while (p->Getright() != nullptr)
                p = p->Getright();
            n->Setkey(p->Getkey());
            deleteNode(p);
        }
    }
}

void BST::printTree(Node* root, int space) {
    int COUNT = 5;
    if (root == nullptr) return;
    space += COUNT;
    printTree(root->Getright(), space);
    cout << endl;
    for (int i = COUNT; i < space; i++) cout << " ";
    cout << root->Getkey() << "\n";
    printTree(root->Getleft(), space);
}
void BST::display() {
    printTree(this->root, 0);
}


int BST::sumTree() {
    if (this->root == nullptr) return 0;
    queue<Node*> q;
    q.push(this->root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        sum += curr->Getkey();

        if (curr->Getleft() != nullptr)
            q.push(curr->Getleft());
        if (curr->Getright() != nullptr)
            q.push(curr->Getright());
    }
    return this->sum;
}

int BST::findMin() {
    Node* r = this->root;
    while (r->Getleft() != nullptr) {
        r = r->Getleft();
    }
    return r->Getkey();
}

int BST::findMax() {
    Node* r = this->root;
    while (r->Getright() != nullptr) {
        r = r->Getright();
    }
    return r->Getkey();
}
int BST::GetnumNode() {
    if (this->root == nullptr) return 0;
    queue<Node*> q;
    q.push(this->root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        this->numNode += 1;

        if (curr->Getleft() != nullptr)
            q.push(curr->Getleft());
        if (curr->Getright() != nullptr)
            q.push(curr->Getright());
    }
    return this->numNode;
}

int BST::countLeaf() {
    if (this->root == nullptr) return 0;
    queue<Node*> q;
    int count = 0;
    q.push(this->root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (curr->Getleft() == nullptr && curr->Getright() == nullptr) count++;
        if (curr->Getleft() != nullptr)
            q.push(curr->Getleft());
        if (curr->Getright() != nullptr)
            q.push(curr->Getright());
    }
    return count;
}