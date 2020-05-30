#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* recursive solution */

class Solution_Recursion {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode* temp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(temp);
        return root;
    }
};

/* stack solution */

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==NULL) return NULL;
		stack<TreeNode*> s;
		s.push(root);
		while(!s.empty()){
			TreeNode* new_node = s.top(); s.pop();
			if(new_node){
				TreeNode* temp_node = new_node->left;
				new_node->left = new_node->right;
				new_node->right = temp_node;
				s.push(new_node->left);
				s.push(new_node->right);
			}
		}
        return root;
    }
};
