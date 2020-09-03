/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		stack<TreeNode*> s;
		stack<int> s_s;
		stack<bool> s_v;
		vector<int> p;

		if(root){
			s.push(root);
			s_s.push(0);
			s_v.push(false);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			bool visited = s_v.top(); s_v.pop();
			int prev_sum = s_s.top(); s_s.pop();

			if(visited){
				// delete current node from path
				p.pop_back();
			}
			else{
				// update res
				p.push_back(tmp->val);
				prev_sum += tmp->val;
				if((NULL==tmp->left)&&(NULL==tmp->right)&&(sum==prev_sum)){
					res.push_back(p);
				}
				// post order
				s.push(tmp);
				s_s.push(prev_sum-tmp->val);
				s_v.push(true);
				if(tmp->right){
					s.push(tmp->right);
					s_s.push(prev_sum);
					s_v.push(false);
				}
				if(tmp->left){
					s.push(tmp->left);
					s_s.push(prev_sum);
					s_v.push(false);
				}
			}
		}

		return res;
    }
};
