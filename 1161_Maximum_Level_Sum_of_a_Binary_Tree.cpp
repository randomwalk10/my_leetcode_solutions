/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level X such that the sum of all the values of nodes at level X is maximal.

 

Example 1:


Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-level-sum-of-a-binary-tree
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
    int maxLevelSum(TreeNode* root) {
		stack<TreeNode*> s;
		stack<int> s_d;
		vector<int> sums;

		s.push(root);
		s_d.push(1);
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int d = s_d.top(); s_d.pop();

			if(d>sums.size()) sums.push_back(tmp->val);
			else sums[d-1] += tmp->val;

			if(tmp->right){
				s.push(tmp->right);
				s_d.push(d+1);
			}
			if(tmp->left){
				s.push(tmp->left);
				s_d.push(d+1);
			}
		}

		int max_level = 1;
		int max_sum = sums[max_level-1];
		for (size_t i = 1; i < sums.size(); ++i) {
			if(sums[i]>max_sum){
				max_level = i+1;
				max_sum = sums[i];
			}
		}

		return max_level;
    }
};
