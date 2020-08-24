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
    void flatten(TreeNode* root) {
		if(NULL==root) return;
		stack<TreeNode*> s;

		s.push(root);
		TreeNode* tail = NULL;
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();

			if(tmp->right){
				s.push(tmp->right);
				tmp->right = NULL;
			}
			if(tmp->left){
				s.push(tmp->left);
				tmp->left = NULL;
			}

			if(tail) tail->right = tmp;
			tail = tmp;
		}

		return;
    }
};
