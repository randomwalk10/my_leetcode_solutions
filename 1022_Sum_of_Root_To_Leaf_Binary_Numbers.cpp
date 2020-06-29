/*
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers
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
    int sumRootToLeaf(TreeNode* root) {
		if(NULL==root) return 0;
		int res = 0;
		stack<TreeNode*> s_parent;
		stack<int> s_sum;
		
		s_parent.push(root);
		s_sum.push(0);
		while(!s_parent.empty()){
			TreeNode* tmp_node = s_parent.top(); s_parent.pop();
			int tmp_sum = s_sum.top(); s_sum.pop();
			tmp_sum = (tmp_sum<<1) + tmp_node->val;

			if((tmp_node->left==NULL)&&(tmp_node->right==NULL)){
				res += tmp_sum;
				continue;
			}
			if(tmp_node->right){
				s_parent.push(tmp_node->right);
				s_sum.push(tmp_sum);
			}
			if(tmp_node->left){
				s_parent.push(tmp_node->left);
				s_sum.push(tmp_sum);
			}
		}

		return res;
    }
};
