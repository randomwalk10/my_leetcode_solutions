/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-good-nodes-in-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
		stack<TreeNode*> s;
		stack<int> s_max;
		int res = 0;
		if(root){
			s.push(root);
			s_max.push(INT_MIN);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int prev_max = s_max.top(); s_max.pop();
			if(prev_max<=tmp->val){
				res += 1;
				prev_max = tmp->val;
			}
			//right
			if(tmp->right){
				s.push(tmp->right);
				s_max.push(prev_max);
			}
			//left
			if(tmp->left){
				s.push(tmp->left);
				s_max.push(prev_max);
			}
		}
		return res;
    }
};
