#pragma once
#include"WordNode.h"
class BST_Word
{
private:
    WordNode* root;
public:
    BST_Word() : root(nullptr) {}

    void InsertWord(string s);

    void print(WordNode* r);

    WordNode* getRoot() { return root; }
};

