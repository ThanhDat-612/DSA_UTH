#ifndef BST_H
#define BST_H
#include "Node.h"
#include <queue>
class BST
{
private:
    Node* root;
    int sum = 0;
    int numNode = 0;
    //int height=0;
public:
    BST();
    virtual ~BST();

    Node* Getroot() { return root; }
    void Setroot(Node* val) { root = val; }
    bool InsertNode(Node*);
    bool InsertNodeRe(Node*, Node*);
    void deleteNode(Node*);
    void TravelNLR();
    void TravelLNR();
    void TravelLRN();
    void NLR(Node*);
    void LNR(Node*);
    void LRN(Node*);
    Node* search_x(int);
    void printTree(Node*,int);
    void display();
    int sumTree();
    int findMax();
    int findMin();
    int GetnumNode();
    int countLeaf();
    void printFrequency(Node*);
    int getHeight(Node*);
    int sumLevel(Node*, int);
    bool isPrime(int);
    int numPrimeOfTree();
    void deletePrime();
protected:


};

#endif // BST_H
