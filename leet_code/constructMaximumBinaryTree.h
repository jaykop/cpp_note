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

// HINT!: DON'T NEED TO MAKE NEW VECTORS!
// JUST USE INDEX!
class Solution {
public:

	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

		int largest = 0;
		int size = int(nums.size());
		for (int i = 1; i < size; i++) {

			if (nums[largest] < nums[i])
				largest = i;
		}

		TreeNode* root = new TreeNode(nums[largest]);

		if (largest - 1 >= 0) {
			std::vector<int> split_lo(nums.begin(),
				nums.begin() + (largest));
			if (!split_lo.empty())
				root->left = constructMaximumBinaryTree(split_lo);
		}

		if (largest + 1 <= size - 1) {
			std::vector<int> split_hi(nums.begin() + (largest + 1),
				nums.end());
			if (!split_hi.empty())
				root->right = constructMaximumBinaryTree(split_hi);
		}

		return root;

	}
};