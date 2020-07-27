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
    bool isSubtree(TreeNode* s, TreeNode* t) {
		if((NULL==s)&&(NULL==t)) return true;
		else if((NULL==s)||(NULL==t)) return false;
		stack<TreeNode*> s_parent;

		s_parent.push(s);
		while(!s_parent.empty()){
			TreeNode* tmp = s_parent.top(); s_parent.pop();

			if(tmp->val==t->val){
				stack<TreeNode*> s_s, s_t;
				s_s.push(tmp);
				s_t.push(t);
				bool is_ok = true;
				while((!s_s.empty())&&(!s_t.empty())){
					TreeNode* tmp_s = s_s.top(); s_s.pop();
					TreeNode* tmp_t = s_t.top(); s_t.pop();
					if(tmp_s->val!=tmp_t->val){
						is_ok = false;
						break;
					}
					if(tmp_s->left&&tmp_t->left){
						s_s.push(tmp_s->left);
						s_t.push(tmp_t->left);
					}
					else if(tmp_s->left||tmp_t->left){
						is_ok = false;
						break;
					}
					if(tmp_s->right&&tmp_t->right){
						s_s.push(tmp_s->right);
						s_t.push(tmp_t->right);
					}
					else if(tmp_s->right||tmp_t->right){
						is_ok = false;
						break;
					}
				}
				if(s_s.empty()&&s_t.empty()&&is_ok) return true;
			}
			if(tmp->left) s_parent.push(tmp->left);
			if(tmp->right) s_parent.push(tmp->right);
		}

		return false;
    }
};
