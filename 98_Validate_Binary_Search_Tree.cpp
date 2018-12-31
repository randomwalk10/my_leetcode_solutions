/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
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
#include <climits>
#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool isValidBST(TreeNode* root, int low, int high, \
			bool lset, bool hset){
		if(NULL==root) return true;
		if( (lset&&(low>=root->val)) || \
				(hset&&(high<=root->val)) ) return false;
		if(!isValidBST(root->left, low, root->val, lset, true)) return false;
		if(!isValidBST(root->right, root->val, high, true, hset)) return false;
		return true;
	}
public:
    bool isValidBST(TreeNode* root) {
		return isValidBST(root, INT_MIN, INT_MAX, false, false);
    }
};
