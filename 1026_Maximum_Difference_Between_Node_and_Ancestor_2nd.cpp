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
    int maxAncestorDiff(TreeNode* root) {
		stack<TreeNode*> s;
		stack<int> s_min, s_max;
		int res = 0;

		if(root){
			s.push(root);
			s_min.push(root->val);
			s_max.push(root->val);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int prev_min = s_min.top(); s_min.pop();
			int prev_max = s_max.top(); s_max.pop();

			// update res
			int cur_min = (tmp->val<prev_min)?tmp->val:prev_min;
			int cur_max = (tmp->val>prev_max)?tmp->val:prev_max;
			res = ((cur_max-cur_min)>res)?cur_max-cur_min:res;
			// right
			if(tmp->right){
				s.push(tmp->right);
				s_min.push(cur_min);
				s_max.push(cur_max);
			}
			// left
			if(tmp->left){
				s.push(tmp->left);
				s_min.push(cur_min);
				s_max.push(cur_max);
			}
		}

		return res;
    }
};
