/*
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \    
    1   3  

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's value is different.
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
#include "limits.h"
#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void minDiffInBST(TreeNode* root, int& min_diff, int& min_val, int& max_val){
		int temp_min = root->val;
		int temp_max = root->val;
		if(root->left){
			minDiffInBST(root->left, min_diff, min_val, max_val);
			min_diff = (root->val - max_val < min_diff) ? \
					   root->val - max_val : min_diff;
			temp_min = min_val;
		}
		if(root->right){
			minDiffInBST(root->right, min_diff, min_val, max_val);
			min_diff = (min_val - root->val < min_diff) ? \
					   min_val - root->val : min_diff;
			temp_max = max_val;
		}
		min_val = temp_min;
		max_val = temp_max;
	}
public:
    int minDiffInBST(TreeNode* root) {
		int res = INT_MAX;
		int min_val, max_val;
		minDiffInBST(root, res, min_val, max_val);
		return res;
    }
};
