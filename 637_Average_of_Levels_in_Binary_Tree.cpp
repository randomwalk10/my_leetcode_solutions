/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
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
public:
    vector<double> averageOfLevels(TreeNode* root) {
		vector<vector<int>> vals_by_levels;
		vector<double> out;
		findValuesInAllLevels(root, 0, vals_by_levels);
		for(size_t i=0; i<vals_by_levels.size(); ++i){
			double temp = 0;
			for(size_t j=0; j<vals_by_levels[i].size(); ++j){
				temp += (double)vals_by_levels[i][j];
			}
			if(vals_by_levels[i].size()>0)
				temp /= (double)vals_by_levels[i].size();
			out.push_back(temp);
		}
		return out;
    }
private:
	void findValuesInAllLevels(TreeNode* root, int base_level, \
			vector<vector<int>> &vals_by_levels){
		if(root==NULL) return;
		if((int)vals_by_levels.size() < (base_level+1)){
			vector<int> temp = {root->val};
			vals_by_levels.push_back(temp);
		}
		else vals_by_levels[base_level].push_back(root->val);
		findValuesInAllLevels(root->left, base_level+1, vals_by_levels);
		findValuesInAllLevels(root->right, base_level+1, vals_by_levels);
	}
};
