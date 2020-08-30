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
    int sumNumbers(TreeNode* root) {
		stack<TreeNode*> s;
		stack<int> s_presum;
		int res = 0;

		if(root){
			s.push(root);
			s_presum.push(0);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int sum = 10 * s_presum.top(); s_presum.pop();
			sum += tmp->val;

			if((NULL==tmp->left)&&(NULL==tmp->right)){
				res += sum;
			}

			if(tmp->right){
				s.push(tmp->right);
				s_presum.push(sum);
			}
			if(tmp->left){
				s.push(tmp->left);
				s_presum.push(sum);
			}
		}

		return res;
    }
};
