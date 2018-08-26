/*
Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5
You can return this binary search tree:

         4
       /   \
      2     7
     / \   /
    1   3 5
This tree is also valid:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
		if(root==NULL) return new TreeNode(val);

		TreeNode* temp = root;
		bool exitFlag = false;
		do{
			if(val<temp->val){
				if(temp->left)
					temp = temp->left;
				else{
					temp->left = new TreeNode(val);
					exitFlag = true;
				}
			}
			else{
				if(temp->right)
					temp = temp->right;
				else{
					temp->right = new TreeNode(val);
					exitFlag = true;
				}
			}
		}while(!exitFlag);
		
		return root;
    }
};
