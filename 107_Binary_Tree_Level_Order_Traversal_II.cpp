/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]
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
	void levelOrderBottom(TreeNode* root, int depth, \
			vector<vector<int>>& res){
		if(NULL==root) return;

		if(depth>=(int)res.size()){
			//add a new layer
			res.insert(res.begin(), vector<int>(1, root->val));
		}
		else{
			//append to existing layer
			res[res.size()-1-depth].push_back(root->val);
		}

		levelOrderBottom(root->left, depth+1, res);
		levelOrderBottom(root->right, depth+1, res);

		return;
	}
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> out;

		levelOrderBottom(root, 0, out);

		return out;
    }
};
