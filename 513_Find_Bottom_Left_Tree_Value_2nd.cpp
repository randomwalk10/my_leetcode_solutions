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
    int findBottomLeftValue(TreeNode* root) {
		stack<TreeNode*> s;
		stack<int> s_d;
		int res;
		int max_depth = 0;

		s.push(root);
		s_d.push(1);
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int tmp_d = s_d.top(); s_d.pop();

			//right
			if(tmp->right){
				s.push(tmp->right);
				s_d.push(tmp_d+1);
			}
			//left
			if(tmp->left){
				s.push(tmp->left);
				s_d.push(tmp_d+1);
			}
			else if(tmp_d>max_depth){
				res = tmp->val;
				max_depth = tmp_d;
			}
		}

		return res;
    }
};
