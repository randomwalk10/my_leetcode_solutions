/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/same-tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
		if((NULL==p)&&(NULL==q)) return true;
		else if(NULL==p) return false;
		else if(NULL==q) return false;
		stack<TreeNode*> s_p;
		stack<TreeNode*> s_q;

		s_p.push(p);
		s_q.push(q);
		while(!s_p.empty()){
			TreeNode* tmp_p = s_p.top(); s_p.pop();
			TreeNode* tmp_q = s_q.top(); s_q.pop();
			// compare val
			if(tmp_p->val!=tmp_q->val) return false;
			// right
			if((NULL!=tmp_p->right)&&(NULL!=tmp_q->right)){
				s_p.push(tmp_p->right);
				s_q.push(tmp_q->right);
			}
			else if((NULL!=tmp_p->right)||(NULL!=tmp_q->right)) return false;
			// left
			if((NULL!=tmp_p->left)&&(NULL!=tmp_q->left)){
				s_p.push(tmp_p->left);
				s_q.push(tmp_q->left);
			}
			else if((NULL!=tmp_p->left)||(NULL!=tmp_q->left)) return false;
		}

		return true;
    }
};
