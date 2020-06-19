/*
A binary tree is univalued if every node in the tree has the same value.

Return trueif and only if the given tree is univalued.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/univalued-binary-tree
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
		bool isUnivalTree(TreeNode* root) {
			if(root==NULL) return false;
			stack<TreeNode*> s_parent;

			s_parent.push(root);
			int val = root->val;
			while(!s_parent.empty()){
				TreeNode* tmp_node = s_parent.top(); s_parent.pop();
				if(val!=tmp_node->val) return false;
				if(tmp_node->left) s_parent.push(tmp_node->left);
				if(tmp_node->right) s_parent.push(tmp_node->right);
			}

			return true;
		}
};
