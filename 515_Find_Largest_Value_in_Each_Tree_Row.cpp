/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
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
#define NULL 0
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
	void findLargetValues(TreeNode* root, int base_level, vector<int> &max_values){
		if(NULL==root) return;
		if((int)max_values.size()<(base_level+1)){
			max_values.push_back(root->val);
		}
		else{
			max_values[base_level] = (max_values[base_level]<root->val) ? \
									 root->val : max_values[base_level];
		}
		findLargetValues(root->left, base_level+1, max_values);
		findLargetValues(root->right, base_level+1, max_values);
	}
    vector<int> largestValues(TreeNode* root) {
		vector<int> max_values;
		findLargetValues(root, 0, max_values);
		return max_values;
    }
};
