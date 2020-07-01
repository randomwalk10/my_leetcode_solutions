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
    int getMinimumDifference(TreeNode* root) {
		if(NULL==root) return 0;
		stack<TreeNode*> s_parent;
		stack<bool> s_visited;
		bool is_null=true;
		int prev;
		int res = -1;

		s_parent.push(root);
		s_visited.push(false);
		while(!s_parent.empty()){
			TreeNode* tmp_node = s_parent.top(); s_parent.pop();
			bool tmp_visited = s_visited.top(); s_visited.pop();
			if(tmp_visited){
				// update res
				if(is_null){
					is_null = false;
				}
				else{
					if(res>=0){
						res = min(res, tmp_node->val-prev);
					}
					else{
						res = tmp_node->val-prev;
					}
				}
				// update prev
				prev = tmp_node->val;
			}
			else{
				// right
				if(tmp_node->right){
					s_parent.push(tmp_node->right);
					s_visited.push(false);
				}
				// self
				s_parent.push(tmp_node);
				s_visited.push(true);
				// left
				if(tmp_node->left){
					s_parent.push(tmp_node->left);
					s_visited.push(false);
				}
			}
		}

		return res;
    }
};
