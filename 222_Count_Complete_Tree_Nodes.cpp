/*
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-complete-tree-nodes
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
    int countNodes(TreeNode* root) {
		stack<TreeNode*> s;
		int res = 0;

		if(root){
			s.push(root);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			++res;

			if(tmp->right){
				s.push(tmp->right);
			}
			if(tmp->left){
				s.push(tmp->left);
			}
		}

		return res;
    }
};
