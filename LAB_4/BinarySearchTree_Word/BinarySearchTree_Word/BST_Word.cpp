#include "BST_Word.h"
void BST_Word::InsertWord(string s) {
    if (root == nullptr) {
        root = new WordNode(s);
        return;
    }
    WordNode* p = root;
    WordNode* parent = nullptr;
    while (p != nullptr) {
        parent = p;
        if (s == p->getKey()) {
            p->Increment(); 
            return;
        }
        if (s < p->getKey()) p = p->GetLeft();
        else p = p->GetRight();
    }

    if (s < parent->getKey()) parent->SetLeft(new WordNode(s));
    else parent->SetRight(new WordNode(s));
}

void BST_Word::print(WordNode* r) {
    if (r != nullptr) {
        print(r->GetLeft());
        cout << r->getKey() << ": " << r->GetCount() << endl;
        print(r->GetRight());
    }
}