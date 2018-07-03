/*
Given a binary tree, you need to compute the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
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
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int max_path = 0;
	int findDepth(TreeNode* root){
		if(root==NULL) return 0;
		//find the depths of left and right subtrees
		int l_dp = findDepth(root->left);
		int r_dp = findDepth(root->right);
		//update max_path
		max_path = max(l_dp+r_dp, max_path);
		//return depth of root
		return 1 + max(l_dp, r_dp);
	}
public:
    int diameterOfBinaryTree(TreeNode* root) {
		findDepth(root);
		return this->max_path;
    }
};
