#pragma once
#include"AVL_Tree.h"

class Dictionary : public AVL_tree
{
	private:
		Node* seachWord(string);
	public:
		void add(string, string);
		void update(string, string);
		void lookup(string);
};

