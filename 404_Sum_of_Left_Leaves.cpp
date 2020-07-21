/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-left-leaves
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
    int sumOfLeftLeaves(TreeNode* root) {
		if(NULL==root) return 0;
		stack<TreeNode*> s_parent;
		stack<bool> s_left;
		int res = 0;

		s_parent.push(root);
		s_left.push(false);
		while(!s_parent.empty()){
			TreeNode* tmp_node = s_parent.top(); s_parent.pop();
			bool is_left = s_left.top(); s_left.pop();

			if(tmp_node->left){
				s_parent.push(tmp_node->left);
				s_left.push(true);
				is_left = false;
			}
			if(tmp_node->right){
				s_parent.push(tmp_node->right);
				s_left.push(false);
				is_left = false;
			}
			if(is_left) res += tmp_node->val;
		}

		return res;
    }
};
