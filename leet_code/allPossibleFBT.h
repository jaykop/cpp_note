#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

// *Could not solve*

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

	unordered_map<int, vector<TreeNode*>> cache;

	vector<TreeNode*> allPossibleFBT(int N) {

		vector<TreeNode*> node_list;

		// given N is even -> return empty
		if (cache[N].size()) return cache[N];
		else if (N == 1) return { new TreeNode(0)};
		else {
			
			for (int i = 1; i < N-1  ; i+=2) { 
				int l = i;
				int r = N - i - 1;
				for (auto left : allPossibleFBT(l)) { 
					for (auto right : allPossibleFBT(r)) {
						TreeNode* root = new TreeNode(0);
						root->left = left;
						root->right = right;
						node_list.push_back(root);
					}
				}
			}
		}
		cache[N] = node_list;

		return node_list;
	}
};