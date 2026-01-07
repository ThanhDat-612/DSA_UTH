#include "Char_BST.h"

bool Char_BST::InsertNode(CharNode* n) {
    CharNode* p = this->root;
    CharNode* T = nullptr;

    if (root == nullptr) {
        this->root = n;
        return true;
    }

    while (p != nullptr) {
        T = p;
        if (n->Getkey() < p->Getkey()) {
            p = p->Getleft();
        }
        else if (n->Getkey() > p->Getkey()) {
            p = p->Getright();
        }
        else {
            p->Increment(); 
            return false;   
        }
    }
    if (n->Getkey() < T->Getkey())
        T->Setleft(n);
    else
        T->Setright(n);

    n->Setparent(T);
    return true;
}
void Char_BST::NLR(CharNode* r) {
	if (r != nullptr) {
		cout << r->Getkey() << "\n";
		NLR(r->Getleft());
		NLR(r->Getright());
	}
}
// trung to
// be den lon 
void Char_BST::LNR(CharNode* r) {
	if (r != nullptr) {
		LNR(r->Getleft());
		cout << r->Getkey() << "\n";
		LNR(r->Getright());
	}
}
// hau to
void Char_BST::LRN(CharNode* r) {
	if (r != nullptr) {
		LRN(r->Getleft());
		LRN(r->Getright());
		cout << r->Getkey() << "\n";
	}
}
void Char_BST::TravelNLR() {
	NLR(this->root);
}
void Char_BST::TravelLNR() {
	LNR(this->root);
}
void Char_BST::TravelLRN() {
	LRN(this->root);
}

int Char_BST::appearance(CharNode* n) {
    return n->Getcount();
}

void Char_BST::getNodeAppearance(CharNode* r) {
    if (r != nullptr) {
        getNodeAppearance(r->Getleft());
        getNodeAppearance(r->Getright());
        cout << r->Getkey() << " - so lan xuat hien: " << appearance(r)<<endl;
    }
}

CharNode* Char_BST::search_x(CharNode* root, char key) {
    if (root == nullptr || root->Getkey() == key) return root;
    if (root->Getkey() < key) return search_x(root->Getright(),key);
    return search_x(root->Getleft(),key);
}