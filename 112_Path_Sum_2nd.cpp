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
    bool hasPathSum(TreeNode* root, int sum) {
		if(NULL==root) return false;
		stack<TreeNode*> s_parent;
		stack<int> s_sum;

		s_parent.push(root);
		s_sum.push(0);
		while(!s_parent.empty()){
			TreeNode* tmp_node = s_parent.top(); s_parent.pop();
			int tmp_sum = s_sum.top()+tmp_node->val; s_sum.pop();

			if((tmp_sum==sum)&&(NULL==tmp_node->left)&&(NULL==tmp_node->right))
				return true;
			if(tmp_node->right){
				s_parent.push(tmp_node->right);
				s_sum.push(tmp_sum);
			}
			if(tmp_node->left){
				s_parent.push(tmp_node->left);
				s_sum.push(tmp_sum);
			}
		}
		
		return false;
    }
};
