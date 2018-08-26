/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, \
			int l1, int l2, int len) {
		int start = 0;
		int right_idx = len - 1;
		TreeNode* root=NULL;
		TreeNode* left_node=NULL;
		while(start<=right_idx){
			//update left node
			if(NULL==left_node){
				if(inorder[start+l1]==postorder[start+l2])
					left_node = new TreeNode(inorder[start+l1]);
			}
			//search for root node
			if(left_node) start++;
			if(start>right_idx) return (root)?root:left_node;
			root = new TreeNode(inorder[start+l1]);
			root->left = left_node;
			int sub_len;
			for(int i=start; i<len; ++i){
				if(inorder[start+l1]==postorder[i+l2]){
					sub_len = i - start;
				}
			}

			//update right mode
			if(sub_len>0){
				root->right = buildTree(inorder, postorder, \
						start+1+l1, start+l2, sub_len);
			}

			//update start and left_node
			start += sub_len;
			left_node = root; 
		}
		return root;
	}
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(inorder, postorder, 0, 0, inorder.size());
    }
};
