/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
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
    void spearLevelOrder(TreeNode* root, vector<vector<int>>& res, int level){
        if(root==NULL) return;
        else if(level>=(int)res.size()){
            vector<int> temp;
            res.push_back(temp);
        }
		res[level].push_back(root->val);
        spearLevelOrder(root->left, res, level+1);
        spearLevelOrder(root->right, res, level+1);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        spearLevelOrder(root, res, 0);
		for(int level=1; level<(int)res.size(); level+=2){
			std::reverse(res[level].begin(), res[level].end());
		}
        return res;
    }
};
