/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
	void fillInLayers(TreeNode* root, int idx, vector<vector<int>>& layers){
		if(NULL==root) return;
		if(idx<(int)layers.size()){
			layers[idx].push_back(root->val);
		}
		else{
			layers.push_back({root->val});
		}
		fillInLayers(root->left, idx+1, layers);
		fillInLayers(root->right, idx+1, layers);
	}
public:
    vector<int> rightSideView(TreeNode* root) {
		vector<vector<int>> layers;
		vector<int> res;

		//fill in layers(left to right)
		fillInLayers(root, 0, layers);
		//fill in res from layers
		for(int i=0; i<(int)layers.size(); ++i){
			res.push_back(layers[i].back());
		}

		return res;
    }
};
