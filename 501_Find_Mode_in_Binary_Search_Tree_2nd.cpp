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
    vector<int> findMode(TreeNode* root) {
		vector<int> res;
		if(NULL==root) return res;
		int max_count = 0;
		int cur_count = 0;
		stack<TreeNode*> s_parent;
		stack<bool> s_visited;

		s_parent.push(root);
		s_visited.push(false);
		int prev_val;
		while(!s_parent.empty()){
			TreeNode* tmp = s_parent.top(); s_parent.pop();
			bool visited = s_visited.top(); s_visited.pop();

			if(visited){
				// reset cur_count
				if(tmp->val!=prev_val){
					cur_count = 0;
				}
				// update prev_val
				prev_val = tmp->val;
				// update cur_count
				++cur_count;
				// update max_count and res
				if(cur_count>max_count){
					res.clear();
					res.push_back(tmp->val);
					max_count = cur_count;
				}
				else if(cur_count==max_count){
					res.push_back(tmp->val);
				}
			}
			else{
				// right
				if(tmp->right){
					s_parent.push(tmp->right);
					s_visited.push(false);
				}
				// self
				s_parent.push(tmp);
				s_visited.push(true);
				// left
				if(tmp->left){
					s_parent.push(tmp->left);
					s_visited.push(false);
				}
			}
		}

		return res;
    }
};
