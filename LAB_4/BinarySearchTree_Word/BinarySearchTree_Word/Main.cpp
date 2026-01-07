#include "Char_BST.h"
#include"BST_Word.h"
#include <fstream>
int main()
{
    /*ifstream f("data.txt");
    if (!f.is_open()) return 1;

    Char_BST tree;
    char c;

    while (f.get(c)) {

        CharNode* n = new CharNode(c);
        tree.InsertNode(n);
    }
    f.close();
    tree.TravelLRN();
    tree.getNodeAppearance(tree.getRoot());
    char ch;
    cin >> ch;
    cout << tree.search_x(tree.getRoot(), ch)->Getcount();*/
    ifstream f("data.txt");
        if (!f.is_open()) return 1;

    BST_Word sentenceTree;
    string word;

    // Đọc từng từ cách nhau bởi khoảng trắng
    while (f >> word) {
        sentenceTree.InsertWord(word);
    }
    f.close();

        cout << "Ket qua thong ke tieng:" << endl;
    sentenceTree.print(sentenceTree.getRoot());

    return 0;
}

