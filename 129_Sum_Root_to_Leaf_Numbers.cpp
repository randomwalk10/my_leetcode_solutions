/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
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
	void sumNumbers(TreeNode* root, vector<int>& path, int& sum){
		if(root==NULL) return;
		path.push_back(root->val);
		//end leaf
		if( (root->left==NULL) && (root->right==NULL) ){
			int temp = 0;
			for(size_t i=0; i<path.size(); ++i){
				temp *= 10;
				temp += path[i];
			}
			sum += temp;
			return;
		}
		//drive down
		if(root->left){
			sumNumbers(root->left, path, sum);
			path.pop_back();
		}
		if(root->right){
			sumNumbers(root->right, path, sum);
			path.pop_back();
		}
		return;
	}
public:
    int sumNumbers(TreeNode* root) {
		vector<int> path;
		int sum=0;

		sumNumbers(root, path, sum);

		return sum;
    }
};
