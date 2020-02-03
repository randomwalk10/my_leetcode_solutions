/*
Given the root of a binary search tree with distinct values, modify it so that every node has a new value equal to the sum of the values of the original tree that are greater than or equal to node.val.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Note:

The number of nodes in the tree is between 1 and 100.
Each node will have value between 0 and 100.
The given tree is a binary search tree.
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
	TreeNode* bstToGst(TreeNode* root, int& sum, int& pre){
		if(NULL==root){
			sum = 0;
			return NULL;
		}
		TreeNode* res = new TreeNode(root->val+pre);
		// right
		int sum_r;
		res->right = bstToGst(root->right, sum_r, pre);
		// node
		res->val += sum_r;
		// left
		int sum_l;
		res->left = bstToGst(root->left, sum_l, res->val);
		// sum
		sum = sum_r + root->val + sum_l;
		// return
		return res;
	}
public:
    TreeNode* bstToGst(TreeNode* root) {
		int sum, pre = 0;
		return bstToGst(root, sum, pre);
    }
};
