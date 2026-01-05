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

    cout << tree->getHeight(tree->Getroot())<<"\n";
    //tree->display();
    int level = 1;
    int sumLevel_1 = tree->sumLevel(tree->Getroot(), level);
    cout << sumLevel_1;
    cout << tree->numPrimeOfTree();
    tree->deletePrime();
    tree->TravelLNR();
   /* int numbers[] = { 10, 19, 9, 3, 19, 8, 4, 1, 15, 10, 10 };
    BST* t=new BST();
    for (int i = 0; i < 11; i++) {
        t->InsertNode(new Node(numbers[i]));
    }
    cout << "So phan tu phan biet: " << t->GetnumNode()<<endl;
    t->printFrequency(t->Getroot());*/
    return 0;
}
