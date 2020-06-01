/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

/* O(N) in time and O(N) in space */
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        stack<TreeNode*> s;
        stack<int> d;
        int res = 0;

        s.push(root);
        d.push(1);
        while(!s.empty()){
            TreeNode* temp = s.top(); s.pop();
            int temp2 = d.top(); d.pop();
            res = max(res, temp2);
            if(temp->left){
                s.push(temp->left);
                d.push(temp2+1);
            }
            if(temp->right){
                s.push(temp->right);
                d.push(temp2+1);
            }
        }

        return res;
    }
};
