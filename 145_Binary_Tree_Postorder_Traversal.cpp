/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
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
#include <unordered_set>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> out;
		stack<TreeNode *> s;
		unordered_set<TreeNode *> visited;


		if(NULL==root) return out;
		s.push(root);
		if(root->right) s.push(root->right);
		if(root->left) s.push(root->left);
		visited.insert(root);
		while(!s.empty()){
			TreeNode* new_node = s.top();
			s.pop();
			if(visited.end()!=visited.find(new_node)){
				out.push_back(new_node->val);
				continue;
			}
			visited.insert(new_node);

			s.push(new_node);
			if(new_node->right) s.push(new_node->right);
			if(new_node->left) s.push(new_node->left);
		}

		return out;
    }
};
