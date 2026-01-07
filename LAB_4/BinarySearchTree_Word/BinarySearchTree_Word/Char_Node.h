#pragma once
#include<iostream>
#include <string>
using namespace std;

class CharNode {
private:
    char key;
    int count;
    int ascii;
    CharNode* left, * right, * parent;

public:
    CharNode(char val) {
        key = val;
        count = 1;
        ascii = (int)val;
        left = right = parent = nullptr;
    }
    char Getkey() { return key; }
    int Getcount() { return count; }
    int Getascii() { return ascii; }
    void Increment() { count++; }

    CharNode* Getleft() { return left; }
    void Setleft(CharNode* n) { left = n; }
    CharNode* Getright() { return right; }
    void Setright(CharNode* n) { right = n; }
    CharNode* Getparent() { return parent; }
    void Setparent(CharNode* n) { parent = n; }
};

