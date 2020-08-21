#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
		if(NULL==root) return NULL;
		stack<TreeNode*> s, s_p;
		stack<bool> s_v;
		TreeNode* res = root;

		s.push(root);
		s_p.push(NULL);
		s_v.push(false);
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			TreeNode* tmp_p = s_p.top(); s_p.pop();
			bool visited = s_v.top(); s_v.pop();

			if(visited){
				if((NULL==tmp->left)&&(NULL==tmp->right)&&(0==tmp->val)){
					if(tmp_p){
						if(tmp_p->left==tmp) tmp_p->left = NULL;
						else tmp_p->right = NULL;
					}
					//delete tmp;
					res = NULL;
				}
				else{
					res = tmp;
				}
			}
			else{
				// self
				s.push(tmp);
				s_p.push(tmp_p);
				s_v.push(true);
				// right
				if(tmp->right){
					s.push(tmp->right);
					s_p.push(tmp);
					s_v.push(false);
				}
				// left
				if(tmp->left){
					s.push(tmp->left);
					s_p.push(tmp);
					s_v.push(false);
				}
			}
		}

		return res;
    }
};
