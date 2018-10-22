/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void pathSum(TreeNode* root, int sum, \
			unordered_map<int, int>& count_path_sums, \
			int curSum, int& res){
		if(NULL==root) return;
		
		//keep track of counts of all subpath sums of current path from [root node]
		curSum += root->val;
		res += count_path_sums[curSum-sum];

		//search down the path
		count_path_sums[curSum] += 1;
		pathSum(root->left, sum, count_path_sums, \
				curSum, res);
		pathSum(root->right, sum, count_path_sums, \
				curSum, res);

		//move back to parent node
		count_path_sums[curSum] -= 1;
	}
public:
    int pathSum(TreeNode* root, int sum) {
		unordered_map<int, int> count_path_sums;
		count_path_sums[0] = 1;
		int res = 0;

		pathSum(root, sum, count_path_sums, 0, res);

		return res;
    }
};
