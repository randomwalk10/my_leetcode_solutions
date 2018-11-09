/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
	void findRightMostNodes(TreeNode* root, int idx, vector<int>& res){
		if(NULL==root) return;
		if(idx>=(int)res.size()){
			res.push_back(root->val);
		}
		//always right first
		findRightMostNodes(root->right, idx+1, res);
		findRightMostNodes(root->left, idx+1, res);
	}
public:
    vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		findRightMostNodes(root, 0, res);
		return res;
    }
};
