/*
Given a binary tree root, a ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right then move to the right child of the current node otherwise move to the left child.
Change the direction from right to left or right to left.
Repeat the second and third step until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

Example 1:

Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
Example 2:

Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
Example 3:

Input: root = [1]
Output: 0

Constraints:

Each tree has at most 50000 nodes..
Each node's value is between [1, 100].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-zigzag-path-in-a-binary-tree
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
    int longestZigZag(TreeNode* root) {
		int res = 0;
		stack<TreeNode*> s;
		stack<bool> s_left;
		stack<int> s_len;

		if(root){
			s.push(root);
			s_left.push(true);
			s_len.push(0);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			bool is_left = s_left.top(); s_left.pop();
			int len = s_len.top(); s_len.pop();
			res = (len>res)?len:res;

			if(len>0){
				if(is_left){
					if(tmp->left){
						s.push(tmp->left);
						s_left.push(true);
						s_len.push(1);
					}
					if(tmp->right){
						s.push(tmp->right);
						s_left.push(false);
						s_len.push(len+1);
					}
				}
				else{
					if(tmp->right){
						s.push(tmp->right);
						s_left.push(false);
						s_len.push(1);
					}
					if(tmp->left){
						s.push(tmp->left);
						s_left.push(true);
						s_len.push(len+1);
					}
				}
			}
			else{
				if(tmp->right){
					s.push(tmp->right);
					s_left.push(false);
					s_len.push(1);
				}
				if(tmp->left){
					s.push(tmp->left);
					s_left.push(true);
					s_len.push(1);
				}
			}
		}

		return res;
    }
};
