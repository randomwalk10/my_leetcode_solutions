/*
Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)
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
#include <stdlib.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int maxAncestorDiff(TreeNode* root, int& max_child, int& min_child){
		if(NULL==root){
			max_child = -1;
			min_child = -1;
			return 0;
		}
		// left
		int temp_min_l, temp_max_l;
		int temp_res_l = maxAncestorDiff(root->left, temp_max_l, temp_min_l);
		// right
		int temp_min_r, temp_max_r;
		int temp_res_r = maxAncestorDiff(root->right, temp_max_r, temp_min_r);
		// compute
		int res = 0;
		max_child = root->val;
		min_child = root->val;
		if(temp_min_l>=0){
			res = (abs(root->val-temp_min_l)>res)?abs(root->val-temp_min_l):res;
			res = (abs(root->val-temp_max_l)>res)?abs(root->val-temp_max_l):res;
			max_child = (temp_max_l>max_child)?temp_max_l:max_child;
			min_child = (temp_min_l<min_child)?temp_min_l:min_child;
		}
		if(temp_min_r>=0){
			res = (abs(root->val-temp_min_r)>res)?abs(root->val-temp_min_r):res;
			res = (abs(root->val-temp_max_r)>res)?abs(root->val-temp_max_r):res;
			max_child = (temp_max_r>max_child)?temp_max_r:max_child;
			min_child = (temp_min_r<min_child)?temp_min_r:min_child;
		}
		res = (res>temp_res_l)?res:temp_res_l;
		res = (res>temp_res_r)?res:temp_res_r;
		// return
		return res;
	}
public:
    int maxAncestorDiff(TreeNode* root) {
		int max_val, min_val;
		return maxAncestorDiff(root, max_val, min_val);
    }
};
