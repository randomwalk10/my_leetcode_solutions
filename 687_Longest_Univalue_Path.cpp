/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
int longestUnivaluePath(TreeNode* root, TreeNode* parent, int temp, int& res) {
	if(NULL==root) return 0;

	if( parent && (parent->val==root->val) ){
		temp++;
		res = (temp>res)?temp:res;
	}
	else temp=0;

	int retrieval = this->longestUnivaluePath(root->left, root, temp, res);
	if( root->left && (root->left->val==root->val) ) retrieval++;
	else retrieval=0;

	int retrieval2 = this->longestUnivaluePath(root->right, root, (retrieval>temp)?retrieval:temp, res);
	if( root->right && (root->right->val==root->val) ) retrieval2++;
	else retrieval2=0;

	return (retrieval2>retrieval)?retrieval2:retrieval;
}
public:
    int longestUnivaluePath(TreeNode* root) {
		int res=0;
		this->longestUnivaluePath(root, NULL, 0, res);
		return res;
    }
};
