/*
Given a binary tree, determine if it is a complete binary tree.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example 1:

Input: [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
Example 2:

Input: [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
 
Note:

The tree will have between 1 and 100 nodes.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-completeness-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
		stack<TreeNode*> s;
		stack<int> s_d, s_id;
		vector<int> cnts;

		if(root){
			s.push(root);
			s_d.push(0);
			s_id.push(0);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int d = s_d.top(); s_d.pop();
			int id = s_id.top(); s_id.pop();

			if(d>=(int)cnts.size()){
				if(id!=0) return false;
				cnts.push_back(id+1);
			}
			else{
				if(cnts[d]!=id) return false;
				cnts[d] = id + 1;
			}

			if(tmp->right){
				s.push(tmp->right);
				s_d.push(d+1);
				s_id.push(2*id+1);
			}
			if(tmp->left){
				s.push(tmp->left);
				s_d.push(d+1);
				s_id.push(2*id);
			}
		}

		for (int i = 0; i < (int)cnts.size()-1; ++i) {
			if(cnts[i]!=pow(2, i)) return false;
		}

		return true;
    }
};
