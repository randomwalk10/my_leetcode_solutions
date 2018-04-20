/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
 

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
public:
    void flatten(TreeNode* root) {
		if(NULL==root) return;
		else if(NULL==root->left){
			flatten(root->right);
			return;
		}
		else if(NULL==root->right){
			flatten(root->left);
			root->right = root->left;
			root->left = NULL;
			return;
		}
		TreeNode* r = root->right;
		flatten(root->left);
		root->right = root->left;
		root->left = NULL;
		TreeNode* temp = root;
		while(temp->right){
			temp = temp->right;
		}
		flatten(r);
		temp->right = r;

		return;
    }
};
