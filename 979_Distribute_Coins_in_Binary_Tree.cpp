/*
Given the root of a binary tree with N nodes, each node in the tree has node.val coins, and there are N coins total.

In one move, we may choose two adjacent nodes and move one coin from one node to another.  (The move may be from parent to child, or from child to parent.)

Return the number of moves required to make every node have exactly one coin.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distribute-coins-in-binary-tree
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
    int distributeCoins(TreeNode* root) {
		stack<TreeNode*> s;
		stack<bool> s_v;
		int res = 0;

		if(root){
			s.push(root);
			s_v.push(false);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			bool visited = s_v.top(); s_v.pop();

			if(visited){
				//update res and tmp->val
				if(tmp->left){
					res += (tmp->left->val>0)?tmp->left->val:-tmp->left->val;
					tmp->val += tmp->left->val;
				}
				if(tmp->right){
					res += (tmp->right->val>0)?tmp->right->val:-tmp->right->val;
					tmp->val += tmp->right->val;
				}
				tmp->val -= 1;
			}
			else{
				//self
				s.push(tmp);
				s_v.push(true);
				//right
				if(tmp->right){
					s.push(tmp->right);
					s_v.push(false);
				}
				//left
				if(tmp->left){
					s.push(tmp->left);
					s_v.push(false);
				}
			}
		}

		return res;
    }
};
