#include <stack>
#include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		TreeNode* res = NULL;
		stack<TreeNode*> s;
		stack<int> s_l1, s_r1, s_l2, s_r2;
		unordered_map<int, int> m;

		for (int i = 0; i < inorder.size(); ++i) {
			m[inorder[i]] = i;
		}

		if(!preorder.empty()){
			res = new TreeNode(preorder[0]);
			s.push(res);
			s_l1.push(0); s_r1.push(preorder.size()-1);
			s_l2.push(0); s_r2.push(inorder.size()-1);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int l1 = s_l1.top(); s_l1.pop();
			int r1 = s_r1.top(); s_r1.pop();
			int l2 = s_l2.top(); s_l2.pop();
			int r2 = s_r2.top(); s_r2.pop();

			int mi = m[tmp->val];
			if(mi>l2){
				tmp->left = new TreeNode(preorder[l1+1]);
				s.push(tmp->left);
				s_l1.push(l1+1); s_r1.push(l1+mi-l2);
				s_l2.push(l2); s_r2.push(mi-1);
			}
			if(r2>mi){
				tmp->right = new TreeNode(preorder[r1-(r2-mi)+1]);
				s.push(tmp->right);
				s_l1.push(r1-(r2-mi)+1); s_r1.push(r1);
				s_l2.push(mi+1); s_r2.push(r2);
			}
		}

		return res;
    }
};
