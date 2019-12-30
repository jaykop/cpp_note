#pragma once
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	void getElements(TreeNode* root, vector<int>& output) {

		// if root is not null,
		if (root) {

			// in order search
			getElements(root->left, output);
			output.push_back(root->val);
			getElements(root->right, output);
		}
	}

	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

		vector<int> t1;
		vector<int> t2;
		vector<int> final_output;

		// search thru each root
		getElements(root1, t1);
		getElements(root2, t2);

		int t1_size = int(t1.size()), t2_size = int(t2.size());

		// if one of lists is empty,
		// just return the the other
		if (!t1_size && t2_size) return t2;
		else if (t1_size && !t2_size) return t1;

		// init index
		int i = 0, j = 0;
		while (i < t1_size && j < t2_size) {

			if (t1[i] < t2[j]) {
				final_output.push_back(t1[i]);
				i++;
			}
			else {
				final_output.push_back(t2[j]);
				j++;
			}
		}

		while (i != t1_size)
			final_output.push_back(t1[i++]);
		while (j != t2_size)
			final_output.push_back(t2[j++]);

		return final_output;
	}
};