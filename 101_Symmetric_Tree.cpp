/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Follow up: Solve it both recursively and iteratively.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    bool isSymmetric(TreeNode* root) {
		if(NULL==root) return true;
		stack<TreeNode*> sl, sr;

		sl.push(root);
		sr.push(root);
		while(!sl.empty()){
			TreeNode* tmp_l = sl.top(); sl.pop();
			TreeNode* tmp_r = sr.top(); sr.pop();

			if(tmp_l->val!=tmp_r->val) return false;
			// left
			if(tmp_l->left&&tmp_r->right){
				sl.push(tmp_l->left);
				sr.push(tmp_r->right);
			}
			else if(tmp_l->left||tmp_r->right) return false;
			// right
			if(tmp_l->right&&tmp_r->left){
				sl.push(tmp_l->right);
				sr.push(tmp_r->left);
			}
			else if(tmp_l->right||tmp_r->left) return false;
		}

		return true;
    }
};
