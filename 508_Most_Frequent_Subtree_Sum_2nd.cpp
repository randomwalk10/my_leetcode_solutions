#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
		stack<TreeNode*> s, s_p;
		stack<bool> s_v;
		vector<int> res;
		unordered_map<int, int> m;
		int max_cnt = 0;

		if(root){
			s.push(root);
			s_p.push(NULL);
			s_v.push(false);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			TreeNode* tmp_p = s_p.top(); s_p.pop();
			bool visited = s_v.top(); s_v.pop();

			if(visited){
				m[tmp->val] += 1;
				int cur_cnt = m[tmp->val];
				if(cur_cnt>max_cnt){
					max_cnt = cur_cnt;
					res = {tmp->val};
				}
				else if(cur_cnt==max_cnt){
					res.push_back(tmp->val);
				}

				if(tmp_p) tmp_p->val += tmp->val;
			}
			else{
				//self
				s.push(tmp);
				s_p.push(tmp_p);
				s_v.push(true);
				//right
				if(tmp->right){
					s.push(tmp->right);
					s_p.push(tmp);
					s_v.push(false);
				}
				//left
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
