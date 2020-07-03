/*
Given a binary tree, return the tilt of the whole tree.

The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.

The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input: 
         1
       /   \
      2     3
Output: 1
Explanation: 
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1
Note:

The sum of node values in any subtree won't exceed the range of 32-bit integer.
All the tilt values won't exceed the range of 32-bit integer.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-tilt
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int sum_and_diff(TreeNode* root, int& diff){
        if(root==NULL) return 0;
		int sum_l = sum_and_diff(root->left, diff);
		int sum_r = sum_and_diff(root->right, diff);
		if(sum_l>sum_r) diff += sum_l-sum_r;
		else diff += sum_r-sum_l;
		return root->val + sum_l + sum_r;
    }
public:
    int findTilt(TreeNode* root) {
        int diff=0;
        sum_and_diff(root, diff);
        return diff;
    }
};
