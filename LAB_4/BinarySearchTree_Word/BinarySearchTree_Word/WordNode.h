#pragma once
#include "Char_BST.h" 

class WordNode {
private:
    string key;
    Char_BST* charTree;
    int count;
    WordNode* left, * right;

public:
    WordNode(string s);

    string getKey() { return key; }
    int GetCount() { return count; }
    void Increment() { count++; }

    Char_BST* GetCharTree() { return charTree; }

    WordNode* GetLeft() { return left; }
    void SetLeft(WordNode* n) { left = n; }
    WordNode* GetRight() { return right; }
    void SetRight(WordNode* n) { right = n; }
};