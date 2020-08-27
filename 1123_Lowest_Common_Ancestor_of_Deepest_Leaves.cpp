/*
Given a rooted binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0, and if the depth of a node is d, the depth of each of its children is d+1.
The lowest common ancestor of a set S of nodes is the node A with the largest depth such that every node in S is in the subtree with root A.
 

Example 1:

Input: root = [1,2,3]
Output: [1,2,3]
Explanation: 
The deepest leaves are the nodes with values 2 and 3.
The lowest common ancestor of these leaves is the node with value 1.
The answer returned is a TreeNode object (not an array) with serialization "[1,2,3]".
Example 2:

Input: root = [1,2,3,4]
Output: [4]
Example 3:

Input: root = [1,2,3,4,5]
Output: [2,4,5]
 

Constraints:

The given tree will have between 1 and 1000 nodes.
Each node of the tree will have a distinct value between 1 and 1000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-deepest-leaves
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
	TreeNode* lcaDeepestLeaves(TreeNode* root, int& max_depth){
		if(NULL==root) return NULL;
		TreeNode* res = NULL;
		max_depth += 1;
		// left
		int max_l = max_depth;
		TreeNode* tmp_l = lcaDeepestLeaves(root->left, max_l);
		// right
		int max_r = max_depth;
		TreeNode* tmp_r = lcaDeepestLeaves(root->right, max_r);
		// self
		if(max_l==max_r) res = root;
		else if(max_l>max_r) res = tmp_l;
		else res = tmp_r;
		max_depth = (max_l>max_r)?max_l:max_r;
		// return
		return res;
	}
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
		int max_depth = 0;
		return lcaDeepestLeaves(root, max_depth);
    }
};
