#pragma once
#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "Node.h"

class AVL_tree
{
public:
    AVL_tree();
    virtual ~AVL_tree();
    Node* Getroot() { return root; }
    void Setroot(Node* val) { root = val; }
    bool InsertNode(Node*);
    Node* InsertNode(Node*, Node*);
    void InsertNodeRe(Node*);
    void deleteNode(Node*);
    void TravelNLR();
    void TravelLNR();
    void TravelLRN();
    void NLR(Node*);
    void LNR(Node*);
    void LRN(Node*);
    void LeftRotate(Node*&);
    void RightRotate(Node*&);
    int CheckBal(Node*);
    int GetHeight(Node*);
    Node* search_x(int);
    int getStep() { return this->step; }
protected:

private:
    Node* root;

    int nNum; // Node number of tree
    int height; //height of tree
    int step;

};

#endif // AVL_TREE_H