#pragma once
#include"Char_Node.h"
class Char_BST
{
	private:
		CharNode* root;
	public:
		Char_BST() : root(nullptr) {}
		CharNode* getRoot() { return this->root; }
		bool InsertNode(CharNode*);
		void NLR(CharNode*);
		void LNR(CharNode*);
		void LRN(CharNode*);

		void TravelNLR();
		void TravelLNR();
		void TravelLRN();

		int appearance(CharNode*);
		void getNodeAppearance(CharNode*);
		CharNode* search_x(CharNode*, char);
};

