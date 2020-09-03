/*
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
#include <vector>
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
    vector<int> largestValues(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> s;
		stack<int> s_d;

		if(root){
			s.push(root);
			s_d.push(0);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int d = s_d.top(); s_d.pop();

			if(d<res.size()){
				res[d] = (tmp->val>res[d])?tmp->val:res[d];
			}
			else{
				res.push_back({tmp->val});
			}

			if(tmp->right){
				s.push(tmp->right);
				s_d.push(d+1);
			}
			if(tmp->left){
				s.push(tmp->left);
				s_d.push(d+1);
			}
		}

		return res;
    }
};
