#include "BSTree.h"
#include <vector>

void BSTree::insert(const int& value) throw(BSTException)
{
	insert_item(m_pRoot, value);
}

void BSTree::insert_item(BinTreeNode* tree, int Data) {

	if (tree == 0) tree = MakeNode(Data);
	else if (Data < tree->data) insert_item(tree->pLeft, Data);
	else if (Data > tree->data) insert_item(tree->pRight, Data);
	//else cout << "Error, duplicate item" << endl;
}

void BSTree::delete_item(BinTreeNode* tree, int Data)
{
	if (tree == 0) return;
	else if (Data < tree->data) delete_item(tree->pLeft, Data);
	else if (Data > tree->data) delete_item(tree->pRight, Data);
	else { // (Data == tree->data) 
		if (tree->pLeft == 0) {
			BinTreeNode* temp = tree;
			tree = tree->pRight;
			FreeNode(temp);
		}
		else if (tree->pRight == 0) {
			BinTreeNode* temp = tree;
			tree = tree->pLeft;
			FreeNode(temp);
		}
		else {
			BinTreeNode pred = 0;
			FindPredecessor(tree, pred);
			tree->data = pred->data;
			delete_item(tree->pLeft, tree->pRight);
		}
	}
}

void FindPredecessor(Tree tree, Tree& predecessor) {
	predecessor = tree->left; 
	while (predecessor->right != 0) 
		predecessor = predecessor->right;
}