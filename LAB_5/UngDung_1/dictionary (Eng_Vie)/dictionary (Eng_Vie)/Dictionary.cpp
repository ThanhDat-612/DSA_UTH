#include "Dictionary.h"
#include<iostream>
Node* Dictionary::seachWord(string key) {
	Node* p = this->Getroot();
	while (p != nullptr) {
		if (key == p->Getkey()) return p;
		if (key < p->Getkey()) p = p->Getleft();
		else p = p->Getright();
	}
	return nullptr;
}

void Dictionary::add(string key, string mean) {
	Node* p = seachWord(key);
	if (p==nullptr) {
		Node* n = new Node(key, mean);
		this->InsertNode(n);
		cout << "Added new word"<<endl;
	}
	else {
		cout << "Already had in Dictionary!"<<endl;
	}
}

void Dictionary::update(string key, string mean) {
	Node* p = seachWord(key);
	if (p != nullptr) {
		p->setMean(mean);
		cout << "Update succeed!" << endl;
	}
	else {
		this->add(key, mean);
	}
}

void Dictionary::lookup(string word) {
	Node* p = seachWord(word);
	if (p != nullptr) {
		cout << word << ": " << p->getMean() << endl;
	}
	else {
		cout << "Not found!" << endl;
	}
}