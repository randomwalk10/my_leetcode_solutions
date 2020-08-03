/*
Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)

If there are no nodes with an even-valued grandparent, return 0.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-nodes-with-even-valued-grandparent
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

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
    int sumEvenGrandparent(TreeNode* root) {
		if(NULL==root) return 0;
		int res = 0;
		stack<TreeNode*> s_gp, s_p, s;

		s.push(root);
		s_p.push(NULL);
		s_gp.push(NULL);
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			TreeNode* tmp_p = s_p.top(); s_p.pop();
			TreeNode* tmp_gp = s_gp.top(); s_gp.pop();
			if(tmp_gp&&(tmp_gp->val%2==0)) res += tmp->val;


			if(tmp->right){
				s.push(tmp->right);
				s_p.push(tmp);
				s_gp.push(tmp_p);
			}
			if(tmp->left){
				s.push(tmp->left);
				s_p.push(tmp);
				s_gp.push(tmp_p);
			}
		}

		return res;
    }
};
