#include "WordNode.h"
WordNode::WordNode(string s) {
    key = s;
    count = 1;
    left = right = nullptr;
    charTree = new Char_BST();
    for (char c : s) {
        CharNode* n = new CharNode(c);
        charTree->InsertNode(n);
    }
}