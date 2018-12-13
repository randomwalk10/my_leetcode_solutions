/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, \
			int pre_l, int pre_r, int in_l, int in_r, unordered_map<int, int>& m){
		if(pre_l>pre_r) return NULL;
		int in_m = m[preorder[pre_l]];
		TreeNode* res = new TreeNode(inorder[in_m]);
		res->left = buildTree(preorder, inorder, pre_l+1, in_m-in_l+pre_l, in_l, in_m-1, m);
		res->right = buildTree(preorder, inorder, in_m-in_l+pre_l+1, pre_r, in_m+1, in_r, m);

		return res;
	}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if(preorder.empty()) return NULL;
		unordered_map<int, int> m;//value to index in inorder
		//fill in m
		for(int i=0; i<(int)inorder.size(); ++i){
			m[inorder[i]] = i;
		}
		//build tree
		return buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, m);
    }
};
