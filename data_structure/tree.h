#pragma once

struct TreeNode {

	int val;
	TreeNode *left, *right;

	TreeNode(int v = 0) : val(v), left(nullptr), right(nullptr) {}

};

class Tree {

public: 

	static TreeNode* make_node(int val) {
		return new TreeNode(val);
	}

	void insert(TreeNode* n);
	void remove(TreeNode* n);
	TreeNode* find(int val);
	void rotate();

	TreeNode* root_;
};