/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
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
#include <algorithm>
#include <limits.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int maxPathSum(TreeNode* root, int& max_sum){
		if(NULL==root){
			return 0;
		}
		//left
		int left_sum = maxPathSum(root->left, max_sum); 
		//right
		int right_sum = maxPathSum(root->right, max_sum); 
		//self
		//max_sum
		int temp_sum = 0;
		if(left_sum>0) temp_sum += left_sum;
		if(right_sum>0) temp_sum += right_sum;
		temp_sum += root->val;
		max_sum = max(max_sum, temp_sum);
		//max_path_sum
		int max_path_sum = max(root->val + left_sum, root->val + right_sum);
		max_path_sum = max(max_path_sum, root->val);
		//return
		return max_path_sum;
	}
public:
    int maxPathSum(TreeNode* root) {
		int res = INT_MIN;
		maxPathSum(root, res);
		return res;

    }
};
