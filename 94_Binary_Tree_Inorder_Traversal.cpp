/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
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
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//recursion solution
/*
class Solution {
private:
	void inorderTraversal(TreeNode* root, vector<int>& out){
		if(root==NULL) return;
		inorderTraversal(root->left, out);
		out.push_back(root->val);
		inorderTraversal(root->right, out);
	}
public:
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> out;

		inorderTraversal(root, out);

		return out;
    }
};
*/

//iterative solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> out;

		stack<TreeNode*> parent_nodes;
		while( root || (!parent_nodes.empty()) ){
			//find the leftmost node
			while(root){
				parent_nodes.push(root);
				root = root->left;
			}
			//append to out
			root = parent_nodes.top();
			out.push_back(root->val);
			parent_nodes.pop();
			//switch to right node
			root = root->right;
		}

		return out;
    }
};

