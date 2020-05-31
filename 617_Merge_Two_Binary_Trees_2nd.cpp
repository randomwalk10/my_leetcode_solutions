/* iterative solution */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if(t1==NULL) return t2;
		if(t2==NULL) return t1;
		stack<TreeNode*> s1, s2;
		s1.push(t1);
		s2.push(t2);
		while(!s1.empty()){
			TreeNode *temp1, *temp2;
			temp1 = s1.top(); s1.pop();
			temp2 = s2.top(); s2.pop();
			temp1->val += temp2->val;
			// left
			if((temp1->left!=NULL)&&(temp2->left!=NULL)){
				s1.push(temp1->left);
				s2.push(temp2->left);
			}
			else if(temp2->left!=NULL)
				temp1->left = temp2->left;
			// right
			if((temp1->right!=NULL)&&(temp2->right!=NULL)){
				s1.push(temp1->right);
				s2.push(temp2->right);
			}
			else if(temp2->right!=NULL)
				temp1->right = temp2->right;
		}
		return t1;
    }
};
