/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 

Note: There are at least two nodes in this BST.
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
using namespace std;
#define NULL 0

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void getMinimumDifference(TreeNode* root, int low, int high, int & mindiff){
		if(NULL==root) return;
		//update mindiff
		if(INT_MAX!=high)
			mindiff = ( (high-root->val)<mindiff ) ? (high-root->val) : mindiff;
		if(INT_MIN!=low)
			mindiff = ( (root->val-low)<mindiff ) ? (root->val-low) : mindiff;
		//search into child nodes
		this->getMinimumDifference(root->left, low, root->val, mindiff);
		this->getMinimumDifference(root->right, root->val, high, mindiff);
	}
public:
    int getMinimumDifference(TreeNode* root) {
		int low = INT_MIN;
		int high = INT_MAX;
		int res = INT_MAX;

		this->getMinimumDifference(root, low, high, res);

		return res;
    }
};
