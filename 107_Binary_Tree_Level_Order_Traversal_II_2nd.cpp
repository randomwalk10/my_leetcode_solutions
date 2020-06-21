#include <vector>
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
		vector<vector<int>> levelOrderBottom(TreeNode* root) {
			if(root==NULL) return {};
			stack<TreeNode*> s_parent;
			stack<int> s_depth;
			// get max depth
			int max_depth = 1;
			s_parent.push(root);
			s_depth.push(1);
			while(!s_parent.empty()){
				TreeNode* tmp_node = s_parent.top(); s_parent.pop();
				int tmp_depth = s_depth.top(); s_depth.pop();
				max_depth = max(tmp_depth, max_depth);
				if(tmp_node->right){
					s_parent.push(tmp_node->right);
					s_depth.push(tmp_depth+1);
				}
				if(tmp_node->left){
					s_parent.push(tmp_node->left);
					s_depth.push(tmp_depth+1);
				}
			}
			// fill in res
			vector<vector<int>> res(max_depth, vector<int>());
			s_parent.push(root);
			s_depth.push(1);
			while(!s_parent.empty()){
				TreeNode* tmp_node = s_parent.top(); s_parent.pop();
				int tmp_depth = s_depth.top(); s_depth.pop();
				res[max_depth-tmp_depth].push_back(tmp_node->val);
				if(tmp_node->right){
					s_parent.push(tmp_node->right);
					s_depth.push(tmp_depth+1);
				}
				if(tmp_node->left){
					s_parent.push(tmp_node->left);
					s_depth.push(tmp_depth+1);
				}
			}
			// return
			return res;
		}
};
