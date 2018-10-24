/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
		  */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void convertBST(TreeNode* root, int& greater_sum){
		if(NULL==root) return;

		convertBST(root->right, greater_sum);
		root->val += greater_sum;
		greater_sum = root->val;

		convertBST(root->left, greater_sum);
	}
public:
    TreeNode* convertBST(TreeNode* root) {
		int greater_sum = 0;

		convertBST(root, greater_sum);

		return root;
    }
};
