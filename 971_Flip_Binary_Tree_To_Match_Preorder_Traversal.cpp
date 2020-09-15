/*
Given a binary tree with N nodes, each node has a different value from {1, ..., N}.

A node in this binary tree can be flipped by swapping the left child and the right child of that node.

Consider the sequence of N values reported by a preorder traversal starting from the root.  Call such a sequence of N values the voyage of the tree.

(Recall that a preorder traversal of a node means we report the current node's value, then preorder-traverse the left child, then preorder-traverse the right child.)

Our goal is to flip the least number of nodes in the tree so that the voyage of the tree matches the voyage we are given.

If we can do so, then return a list of the values of all nodes flipped.  You may return the answer in any order.

If we cannot do so, then return the list [-1].

Example 1:



Input: root = [1,2], voyage = [2,1]
Output: [-1]
Example 2:



Input: root = [1,2,3], voyage = [1,3,2]
Output: [1]
Example 3:



Input: root = [1,2,3], voyage = [1,2,3]
Output: []
 

Note:

1 <= N <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flip-binary-tree-to-match-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
		if((NULL==root)||(voyage.empty())) return {-1};
		vector<int> res;
		stack<TreeNode*> s;
		stack<int> s_l, s_r;
		const int N = voyage.size();
		vector<int> val2pos(voyage.size(), 0);

		for (int i = 0; i < N; ++i) {
			val2pos[voyage[i]-1] = i;
		}

		s.push(root);
		s_l.push(0);
		s_r.push(N-1);
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int l = s_l.top(); s_l.pop();
			int r = s_r.top(); s_r.pop();
			if((0>l)||(N<=l)||(0>r)||(N<=r)) return {-1};
			if(l>r) return {-1};
			if(tmp->val!=voyage[l]) return {-1};

			if(tmp->left){
				int l_pos = val2pos[tmp->left->val-1];
				if((l_pos==l+1)&&(l_pos<=r)){
					int r_pos = -1;
					if(tmp->right){
						r_pos = val2pos[tmp->right->val-1];
						s.push(tmp->right);
						s_l.push(r_pos);
						s_r.push(r);
					}
					s.push(tmp->left);
					s_l.push(l_pos);
					if(r_pos>=0) s_r.push(r_pos-1);
					else s_r.push(r);
				}
				else if((l_pos>l+1)&&
						(l_pos<=r)){
					if(tmp->right){
						s.push(tmp->right);
						s_l.push(l+1);
						s_r.push(l_pos-1);
					}
					s.push(tmp->left);
					s_l.push(l_pos);
					s_r.push(r);

					res.push_back(tmp->val);
				}
				else return {-1};
			}
			else if(tmp->right){
				int r_pos = val2pos[tmp->right->val-1];
				if((r_pos==l+1)&&(r_pos<=r)){
					s.push(tmp->right);
					s_l.push(r_pos);
					s_r.push(r);
				}
				else return {-1};
			}
			else if(l<r) return {-1};
		}

		return res;
    }
};
