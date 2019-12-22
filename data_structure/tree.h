#pragma once

struct TreeNode {

	int val;
	TreeNode *left, *right;

	TreeNode(int v = 0) : val(v), left(nullptr), right(nullptr) {}

};

class Tree {

	TreeNode* make_node(int val) {
		return new TreeNode(val);
	}

	void insert(TreeNode* n);
	void 
};