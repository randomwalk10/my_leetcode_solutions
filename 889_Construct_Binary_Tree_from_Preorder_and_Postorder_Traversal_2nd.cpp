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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		std::stack<TreeNode*> s;
		std::stack<int> s_l1, s_r1, s_l2, s_r2;
		unordered_map<int, int> m;
		TreeNode* res = NULL;

		for(int i=0; i<(int)post.size(); ++i){
			m[post[i]] = i;
		}

		if(pre.size()!=0){
			s.push(new TreeNode(pre[0]));
			s_l1.push(0); s_r1.push(pre.size()-1);
			s_l2.push(0); s_r2.push(post.size()-1);
			res = s.top();
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int l1 = s_l1.top(); s_l1.pop();
			int r1 = s_r1.top(); s_r1.pop();
			int l2 = s_l2.top(); s_l2.pop();
			int r2 = s_r2.top(); s_r2.pop();
			
			if(l1<r1){
				int post_l = m[pre[l1+1]];
				// left
				tmp->left = new TreeNode(pre[l1+1]);
				s.push(tmp->left);
				s_l1.push(l1+1); s_r1.push(l1+1+post_l-l2);
				s_l2.push(l2); s_r2.push(post_l);
				// right
				if(post_l+1<r2){
					tmp->right = new TreeNode(post[r2-1]);
					s.push(tmp->right);
					s_l1.push(l1+1+post_l-l2+1); s_r1.push(r1);
					s_l2.push(post_l+1); s_r2.push(r2-1);
				}
			}
		}

		return res;
    }
};
