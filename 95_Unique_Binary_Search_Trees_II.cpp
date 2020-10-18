/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

Constraints:

0 <= n <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii
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
private:
	TreeNode* clone(TreeNode* root, int offset){
		if(NULL==root) return NULL;
		stack<TreeNode*> s, s_cp;
		TreeNode* res = new TreeNode(root->val+offset);

		s.push(root);
		s_cp.push(res);
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			TreeNode* tmp_cp = s_cp.top(); s_cp.pop();

			if(tmp->left){
				tmp_cp->left = new TreeNode(tmp->left->val+offset);
				s.push(tmp->left);
				s_cp.push(tmp_cp->left);
			}
			if(tmp->right){
				tmp_cp->right = new TreeNode(tmp->right->val+offset);
				s.push(tmp->right);
				s_cp.push(tmp_cp->right);
			}
		}

		return res;
	}
public:
    vector<TreeNode*> generateTrees(int n) {
		if(n==0) return {};
		vector<vector<TreeNode*>> dp(n+1, vector<TreeNode*>());
		dp[0].push_back(NULL);

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= i; ++j) {
				for (int l = 0; l < (int)dp[j-1].size(); ++l) {
					for (int r = 0; r < (int)dp[i-j].size(); ++r) {
						TreeNode* tmp = new TreeNode(j);
						tmp->left = dp[j-1][l];
						tmp->right = clone(dp[i-j][r], j);
						dp[i].push_back(tmp);
					}
				}
			}
		}

		return dp[n];
    }
};
