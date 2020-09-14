/*
You are given a binary tree in which each node contains an integer value (which might be positive or negative). Design an algorithm to count the number of paths that sum to a given value. The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

Example:
Given the following tree and  sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
Output:

3
Explanation: Paths that have sum 22 are: [5,4,11,2], [5,8,4,5], [4,11,7]
Note:

node number <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/paths-with-sum-lcci
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
    int pathSum(TreeNode* root, int sum) {
		int res = 0;
		stack<TreeNode*> s;
		stack<bool> s_v;
		vector<int> sums;

		if(root){
			s.push(root);
			s_v.push(false);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			bool visited = s_v.top(); s_v.pop();

			if(visited){
				sums.pop_back();
				for (int i = 0; i < sums.size(); ++i) {
					sums[i] -= tmp->val;
				}
			}
			else{
				sums.push_back(0);
				for (int i = 0; i < sums.size(); ++i) {
					sums[i] += tmp->val;
					if(sums[i]==sum) ++res;
				}

				s.push(tmp);
				s_v.push(true);
				if(tmp->right){
					s.push(tmp->right);
					s_v.push(false);
				}
				if(tmp->left){
					s.push(tmp->left);
					s_v.push(false);
				}
			}
		}

		return res;
    }
};
