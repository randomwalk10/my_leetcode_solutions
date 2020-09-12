/*
We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.

Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
 

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
	void distanceK(TreeNode* root, TreeNode* target, int K, int& cur_dist, vector<int>& res){
		if(NULL==root) return;
		if(root==target) cur_dist=0;
		if(cur_dist>=0){
			if(cur_dist==K){
				res.push_back(root->val);
				return;
			}
			cur_dist += 1;
			distanceK(root->left, target, K, cur_dist, res);
			cur_dist -= 1;
			cur_dist += 1;
			distanceK(root->right, target, K, cur_dist, res);
			cur_dist -= 1;
			return;
		}
		distanceK(root->left, target, K, cur_dist, res);
		if(cur_dist>=0){
			cur_dist += 1;
			if(cur_dist==K){
				res.push_back(root->val);
				return;
			}
			cur_dist += 1;
			distanceK(root->right, target, K, cur_dist, res);
			cur_dist -= 1;
			return;
		}
		distanceK(root->right, target, K, cur_dist, res);
		if(cur_dist>=0){
			cur_dist += 1;
			if(cur_dist==K){
				res.push_back(root->val);
				return;
			}
			cur_dist += 1;
			distanceK(root->left, target, K, cur_dist, res);
			cur_dist -= 1;
			return;
		}
		return;
	}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		vector<int> res;
		int cur_dist = -1;
		distanceK(root, target, K, cur_dist, res);
		return res;
    }
};
