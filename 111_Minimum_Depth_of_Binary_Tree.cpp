/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
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
    int minDepth(TreeNode* root) {
		int res = 0;
		if(NULL==root) return 0;
		stack<TreeNode*> s;
		stack<int> d;

		s.push(root);
		d.push(1);
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int depth = d.top(); d.pop();

			// update res
			if((NULL==tmp->right)&&(NULL==tmp->left)){
				if(res==0) res = depth;
				else if(res>depth) res = depth;
			}

			// dfs
			if(tmp->right){
				s.push(tmp->right);
				d.push(depth+1);
			}
			if(tmp->left){
				s.push(tmp->left);
				d.push(depth+1);
			}
		}

		return res;
    }
};
