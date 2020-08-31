#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> s;
		stack<int> s_d;

		if(root){
			s.push(root);
			s_d.push(0);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int d = s_d.top(); s_d.pop();

			if(d>=res.size()){
				res.push_back(tmp->val);
			}
			
			// left
			if(tmp->left){
				s.push(tmp->left);
				s_d.push(d+1);
			}
			// right
			if(tmp->right){
				s.push(tmp->right);
				s_d.push(d+1);
			}
		}

		return res;
    }
};
