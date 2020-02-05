/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, \
			bool& is_p, bool& is_q){
		if(root==NULL) return NULL;
		bool is_p_l=false, is_q_l=false;
		TreeNode* l = lowestCommonAncestor(root->left, p, q, is_p_l, is_q_l);
		if(NULL!=l) return l;
		else if((is_p_l&&(root->val==q->val))||(is_q_l&&(root->val==p->val)))
			return root;
		bool is_p_r=false, is_q_r=false;
		TreeNode* r = lowestCommonAncestor(root->right, p, q, is_p_r, is_q_r);
		if(NULL!=r) return r;
		is_p = is_p_l||is_p_r||(root->val==p->val);
		is_q = is_q_l||is_q_r||(root->val==q->val);
		if(is_p&&is_q) return root;
		return NULL;
	}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		bool is_p, is_q;
		return lowestCommonAncestor(root, p, q, is_p, is_q);
    }
};
