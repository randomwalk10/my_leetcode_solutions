/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void searchForEndNode(TreeNode* root, \
			vector<string>& result, string path){
		if(root==NULL) return;
		if(path.empty()) path = std::to_string(root->val);
		else path += "->" + std::to_string(root->val);
		if( (NULL==root->left) && (NULL==root->right) ){
			result.push_back(path);
			return;
		}
		if(root->left) searchForEndNode(root->left, \
				result, path);
		if(root->right) searchForEndNode(root->right, \
				result, path);
	}
    vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> out;
		string path = "";

		searchForEndNode(root, out, path);

		return out;
    }
};
