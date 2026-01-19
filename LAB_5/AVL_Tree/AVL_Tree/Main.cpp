#include <iostream>
#include<fstream>
#include"AVL_Tree.h"
#include"BST.h"
using namespace std;
int main()
{
	/*AVL_tree tree;
	BST bee;
	Node* n1;
	Node* n2;
	int arr[12] = { 1,3,5,7,9,12,15,17,21,23,25,27 };
	for (int i = 0; i < 12; i++) {
		n1 = new Node(arr[i]);
		n2 = new Node(arr[i]);
		bee.InsertNode(n2);
		tree.InsertNode(n1);
	}
	tree.search_x(21);
	bee.search_x(21);
	cout <<"AVT tree search steps: " << tree.getStep()<<endl;
	cout << "BST search steps: " << bee.getStep() << endl;
	ifstream fin("text.txt");

	if (!fin.is_open()) {
		cout << "Khong mo duoc file!" << endl;
		return 0;
	}

	int x;
	while (fin >> x) {         
		Node* n = new Node(x);
		tree.InsertNode(n);
	}

	fin.close();

	tree.TravelLNR();*/

	AVL_tree t;

	ifstream fin("student.txt");

	if (!fin.is_open()) {
		cout << "Khong mo duoc file student.txt" << endl;
		return 0;
	}

	Student s;

	while (fin >> s.id >> s.name >> s.birth >> s.gpa) {
		Node* n = new Node(s);
		t.InsertNode(n);
	}

	fin.close();

}
