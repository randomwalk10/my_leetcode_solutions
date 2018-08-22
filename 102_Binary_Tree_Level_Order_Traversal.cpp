/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
	void levelOrder(TreeNode* root, int level, \
			vector<vector<int>>& out){
		if(NULL==root) return;
		if((int)out.size() > level) out[level].push_back(root->val);
		else out.push_back({root->val});

		levelOrder(root->left, level+1, out);
		levelOrder(root->right, level+1, out);
		return;
	}
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> out;

		levelOrder(root, 0, out);

		return out;
    }
};
