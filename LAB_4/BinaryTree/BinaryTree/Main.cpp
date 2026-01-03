#include <iostream>
#include "BST.h"
using namespace std;

int main()
{

    BST* tree = new BST();
    Node* n;
    n = new Node(10);
    tree->InsertNode(n);
    n = new Node(19);
    tree->InsertNode(n);
    n = new Node(9);
    tree->InsertNode(n);
    n = new Node(3);
    tree->InsertNode(n);
    n = new Node(19);
    tree->InsertNode(n);
    n = new Node(8);
    tree->InsertNode(n);
    n = new Node(4);
    tree->InsertNode(n);
    n = new Node(1);
    tree->InsertNode(n);
    n = new Node(15);
    tree->InsertNode(n);

    tree->TravelLNR();
    cout << "------------" << endl;
    Node* nodeDelete = tree->search_x(9);
    tree->deleteNode(nodeDelete);
    tree->TravelLNR();
    cout << "------------" << endl;
    cout << tree->sumTree();
    cout << tree->findMax();
    cout << tree->findMin();
    cout << "------------" << endl;
    cout << tree->GetnumNode();
    cout << tree->countLeaf();
    //tree->display();
    

    return 0;
}
