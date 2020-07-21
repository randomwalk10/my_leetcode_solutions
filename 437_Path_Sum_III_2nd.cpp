#include <stack>
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
    int pathSum(TreeNode* root, int sum) {
		if(NULL==root) return 0;
		stack<TreeNode*> s_parent;
		stack<bool> s_visited;
		unordered_map<int, int> m_cnt;
		int cur_sum = 0;
		int res = 0;

		s_parent.push(root);
		s_visited.push(false);
		m_cnt[0] = 1;
		while(!s_parent.empty()){
			TreeNode* tmp_node = s_parent.top(); s_parent.pop();
			bool is_visited = s_visited.top(); s_visited.pop();

			if(is_visited){
				// update m_cnt
				unordered_map<int, int>::iterator iter = m_cnt.find(cur_sum);
				if(iter->second==1){
					m_cnt.erase(iter);
				}
				else{
					iter->second -= 1;
				}
				// update cur_sum
				cur_sum -= tmp_node->val;
			}
			else{
				// update cur_sum
				cur_sum += tmp_node->val;
				// update res
				unordered_map<int, int>::iterator iter = m_cnt.find(cur_sum-sum);
				if(iter!=m_cnt.end()){
					res += iter->second;
				}
				// update m_cnt
				m_cnt[cur_sum] += 1;

				//post order
				//self
				s_parent.push(tmp_node);
				s_visited.push(true);
				//right
				if(tmp_node->right){
					s_parent.push(tmp_node->right);
					s_visited.push(false);
				}
				//left
				if(tmp_node->left){
					s_parent.push(tmp_node->left);
					s_visited.push(false);
				}
			}
		}

		return res;
    }
};
