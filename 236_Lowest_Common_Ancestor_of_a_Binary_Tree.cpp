/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
             according to the LCA definition.
Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
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
#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, \
									bool &foundp, bool &foundq){
		if(NULL==root) return NULL;
		bool prev_foundp = foundp;
		bool prev_foundq = foundq;

		TreeNode* temp;
		temp = lowestCommonAncestor(root->left, p, q, foundp, foundq);
		if(temp) return temp;

		if(root==p) foundp=true;
		if(root==q) foundq=true;

		temp = lowestCommonAncestor(root->right, p, q, foundp, foundq);
		if(temp) return temp;

		if(foundp&&foundq){
			if((!prev_foundp)&&(!prev_foundq)) return root;
			else return NULL;
		}

		return NULL;
	}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		bool foundp = false;
		bool foundq = false;

		return lowestCommonAncestor(root, p, q, foundp, foundq);
    }
};


