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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*> s, s_p, s_q;
		stack<bool> s_v;
		TreeNode* res = NULL;
		bool is_p_found = false, is_q_found = false;

		if(root){
			s.push(root);
			s_v.push(false);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			bool visited = s_v.top(); s_v.pop();

			if(visited){
				if(tmp->val==p->val) is_p_found = true;
				if(tmp->val==q->val) is_q_found = true;
				if(is_p_found&&is_q_found) break;
				if(!is_p_found) s_p.pop();
				if(!is_q_found) s_q.pop();
			}
			else{
				//self
				s.push(tmp);
				s_v.push(true);
				if(!is_p_found) s_p.push(tmp);
				if(!is_q_found) s_q.push(tmp);
				//right
				if(tmp->right){
					s.push(tmp->right);
					s_v.push(false);
				}
				//left
				if(tmp->left){
					s.push(tmp->left);
					s_v.push(false);
				}
			}
		}
		if(root){
			while(s_p.size()!=s_q.size()){
				if(s_p.size()>s_q.size()) s_p.pop();
				else s_q.pop();
			}
			while(!s_p.empty()){
				if(s_p.top()->val==s_q.top()->val){
					res = s_p.top();
					break;
				}
				s_p.pop(); s_q.pop();
			}
		}

		return res;
    }
};
