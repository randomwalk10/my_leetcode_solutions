/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
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
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode* _first = NULL;
	TreeNode* _second = NULL;
	TreeNode* _prev = NULL;
	void transverseTree(TreeNode* root){
		if(NULL==root) return;
		//left
		transverseTree(root->left);
		//compare and swap
		if( _prev&&(_prev->val>=root->val) ){
			if(NULL==_first){
				_first = _prev;
				_second = root;
			}
			else{
				_second = root;
			}
		}
		//update _prev
		_prev = root;
		//right
		transverseTree(root->right);
	}
public:
	/* inorder trasverse */
    void recoverTree(TreeNode* root) {
		transverseTree(root);
		swap(_first->val, _second->val);
    }
};
