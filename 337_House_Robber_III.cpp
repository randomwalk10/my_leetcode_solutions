/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <unordered_map>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void rob(TreeNode* root, unordered_map<TreeNode *, vector<int>>& res){
	if(NULL==root) return;
	rob(root->left, res);
	rob(root->right, res);

	int cnt1 = root->val;
	int cnt2 = 0;
	if(root->left){
		cnt1 += res[root->left][1];
		cnt2 += max(res[root->left][0], res[root->left][1]);
	}
	if(root->right){
		cnt1 += res[root->right][1];
		cnt2 += max(res[root->right][0], res[root->right][1]);
	}

	vector<int> cnts = {cnt1, cnt2};
	res[root] = cnts;
}
public:
    int rob(TreeNode* root) {
		if(NULL==root) return 0;
		unordered_map<TreeNode*, vector<int>> res;

		rob(root, res);

		return max(res[root][0], res[root][1]);
    }
};
