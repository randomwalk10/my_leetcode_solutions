/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void preorderTraversal(TreeNode* root, vector<int>& res){
		if(root==NULL) return;
		res.push_back(root->val);
		preorderTraversal(root->left, res);
		preorderTraversal(root->right, res);
	}
public:
    vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		preorderTraversal(root, res);
		return res;
    }
};
