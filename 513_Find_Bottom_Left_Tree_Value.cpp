/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
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
public:
	int findMaxDepth(TreeNode* root){
		if(root==NULL) return 0;
		int depth_left = findMaxDepth(root->left);
		int depth_right = findMaxDepth(root->right);
		int max_depth = (depth_left<depth_right)?depth_right:depth_left;
		return 1 + max_depth;
	}
	bool findLeftMostAtDepth(TreeNode* root, int depth, int& out){
		if(depth==1){
			out = root->val;
			return true;
		}
		if( (root->left) && findLeftMostAtDepth(root->left, depth-1, out) )
			return true;
		if( (root->right) && findLeftMostAtDepth(root->right, depth-1, out) )
			return true;
		return false;
	}
    int findBottomLeftValue(TreeNode* root) {
		int max_depth = findMaxDepth(root);
		int out;
		findLeftMostAtDepth(root, max_depth, out);
		return out;
    }
};
