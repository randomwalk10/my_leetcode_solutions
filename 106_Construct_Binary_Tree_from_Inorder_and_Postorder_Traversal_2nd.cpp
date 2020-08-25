#include <vector>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		TreeNode* root = NULL;
		stack<TreeNode*> s;
		stack<int> s_l1, s_r1, s_l2, s_r2;
		unordered_map<int, int> m1;

		for (int i = 0; i < inorder.size(); ++i) {
			m1[inorder[i]] = i;
		}

		if(postorder.size()>0){
			root = new TreeNode(postorder[postorder.size()-1]);
			s.push(root);
			s_l1.push(0); s_r1.push(inorder.size()-1);
			s_l2.push(0); s_r2.push(postorder.size()-1);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int l1 = s_l1.top(); s_l1.pop();
			int r1 = s_r1.top(); s_r1.pop();
			int l2 = s_l2.top(); s_l2.pop();
			int r2 = s_r2.top(); s_r2.pop();

			int pivot_idx = m1[tmp->val];
			if(pivot_idx>l1){
				int root_idx = pivot_idx - l1 + l2 - 1;
				tmp->left = new TreeNode(postorder[root_idx]);
				s.push(tmp->left);
				s_l1.push(l1); s_r1.push(pivot_idx-1);
				s_l2.push(l2); s_r2.push(root_idx);
			}
			if(r1>pivot_idx){
				tmp->right = new TreeNode(postorder[r2-1]);
				s.push(tmp->right);
				s_l1.push(pivot_idx+1); s_r1.push(r1);
				s_l2.push(r2-r1+pivot_idx); s_r2.push(r2-1);
			}
		}

		return root;
    }
};
