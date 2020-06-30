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
    TreeNode* convertBST(TreeNode* root) {
		if(NULL==root) return NULL;
		stack<TreeNode*> s_parent;
		stack<bool> s_visited;
		int res = 0;

		s_parent.push(root);
		s_visited.push(false);
		while(!s_parent.empty()){
			TreeNode* tmp_node = s_parent.top(); s_parent.pop();
			bool tmp_visited = s_visited.top(); s_visited.pop();

			if(tmp_visited){
				tmp_node->val += res;
				res = tmp_node->val;
			}
			else{
				//left
				if(tmp_node->left){
					s_parent.push(tmp_node->left);
					s_visited.push(false);
				}
				//self
				s_parent.push(tmp_node);
				s_visited.push(true);
				//right
				if(tmp_node->right){
					s_parent.push(tmp_node->right);
					s_visited.push(false);
				}
			}
		}

		return root;
    }
};
