/*
Given a binary tree, return the sum of values of its deepest leaves.

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The value of nodes is between 1 and 100.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/deepest-leaves-sum
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
    int deepestLeavesSum(TreeNode* root) {
		if(NULL==root) return 0;
		stack<TreeNode*> s;
		stack<int> d;
		int max_depth = 0;
		int res = 0;

		s.push(root);
		d.push(1);
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int depth = d.top(); d.pop();

			if(tmp->left){
				s.push(tmp->left);
				d.push(depth+1);
			}
			if(tmp->right){
				s.push(tmp->right);
				d.push(depth+1);
			}
			if((NULL==tmp->left)&&(NULL==tmp->right)){
				if(depth>max_depth){
					max_depth = depth;
					res = tmp->val;
				}
				else if(depth==max_depth){
					res += tmp->val;
				}
			}
		}

		return res;
    }
};
