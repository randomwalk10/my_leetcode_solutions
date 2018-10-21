/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2
 

return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

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
	void findMode(TreeNode* root, int& max_count, \
			unordered_map<int, int>& dict){
		if(NULL==root) return;

		if(dict.end()==dict.find(root->val)){
			dict[root->val] = 1;
		}
		else{
			dict[root->val] += 1;
		}

		if(dict[root->val]>max_count) max_count = dict[root->val];

		findMode(root->left, max_count, dict);
		findMode(root->right, max_count, dict);

		return;
	}
public:
    vector<int> findMode(TreeNode* root) {
		unordered_map<int, int> _dict;
		int _max_count = 0;
		vector<int> out;

		findMode(root, _max_count, _dict);

		for(unordered_map<int, int>::iterator iter = \
				_dict.begin(); iter != _dict.end(); ++iter){
			if(_max_count==iter->second)
				out.push_back(iter->first);
		}
		return out;
    }
};
