#define NULL 0

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool isValidBST(TreeNode* root, int& l, int& r){
		if(root->left){
			int l1, r1;
			if(false==isValidBST(root->left, l1, r1))
				return false;
			else if(r1>=root->val) return false;
			l = l1;
			r = root->val;
		}
		else{
			l = root->val;
			r = root->val;
		}
		if(root->right){
			int l2, r2;
			if(false==isValidBST(root->right, l2, r2))
				return false;
			else if(l2<=root->val) return false;
			r = r2;
		}
		return true;
	}
public:
    bool isValidBST(TreeNode* root) {
		if(NULL==root) return true;
		int l, r;
		return isValidBST(root, l, r);
    }
};
