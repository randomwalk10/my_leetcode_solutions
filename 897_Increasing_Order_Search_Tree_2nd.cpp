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
		TreeNode* increasingBST(TreeNode* root) {
			if(NULL==root) return NULL;
			TreeNode* res = NULL;
			TreeNode* tail = NULL;
			stack<TreeNode*> s_parent;
			stack<bool> s_visited;

			s_parent.push(root);
			s_visited.push(false);
			while(!s_parent.empty()){
				TreeNode* tmp_node = s_parent.top(); s_parent.pop();
				bool visited = s_visited.top(); s_visited.pop();

				if(visited){
					if(tail){
						tail->right = new TreeNode(tmp_node->val);
						tail = tail->right;
					}
					else{
						res = new TreeNode(tmp_node->val);
						tail = res;
					}
				}
				else{
					if(tmp_node->right){
						s_parent.push(tmp_node->right);
						s_visited.push(false);
					}
					s_parent.push(tmp_node);
					s_visited.push(true);
					if(tmp_node->left){
						s_parent.push(tmp_node->left);
						s_visited.push(false);
					}
				}
			}

			return res;
		}
};
