#pragma once
#include<string>
using namespace std;

#ifndef NODE_H
#define NODE_H
struct Student {
    int id;
    string name;
    int birth;
    float gpa;
};

class Node
{
public:
    Node();
    Node(int);
    virtual ~Node();

    Node* Getleft() { return left; }
    void Setleft(Node* val) { left = val; }
    Node* Getright() { return right; }
    void Setright(Node* val) { right = val; }
    Node* Getparent() { return parent; }
    void Setparent(Node* val) { parent = val; }
    int Getkey() { return key; }
    void Setkey(int val) { key = val; }
    int Getheight() { return height; }
    void Setheight(int val) { height = val; }
    void IncrementCount() { count++; }
    int getCount() { return count; }
    Node(Student s) {
        key = s.id;
        data = s;
        left = right = parent = nullptr;
    }
    Student GetData() { return data; }
protected:

private:
    Node* left;
    Node* right;
    Node* parent;
    // int bal; // -1 0 1
    int key;
    int height;
    int count;
    Student data;
};

#endif // NODE_H
