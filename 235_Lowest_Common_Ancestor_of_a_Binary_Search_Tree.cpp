/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: The lowest common ancestor is defined between two nodes p and qas the lowest node in T that has both p and qas descendants (where we allow a node to be a descendant of itself).

Given binary search tree: root =[6,2,8,0,4,7,9,null,null,3,5]




Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.


Note:

All of the nodes' values will be unique.
p and q are different and both values willexist in the BST.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree
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
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q,
				bool& is_p, bool& is_q){
			is_p = (root==p)?true:false; is_q = (root==q)?true:false;
			if(root==NULL) return NULL;
			TreeNode* res;
			// left
			bool is_p_l, is_q_l;
			res = lowestCommonAncestor(root->left, p, q, is_p_l, is_q_l);
			is_p |= is_p_l; is_q |= is_q_l;
			if(res) return res;
			else if(is_p&&is_q) return root;
			// right
			bool is_p_r, is_q_r;
			res = lowestCommonAncestor(root->right, p, q, is_p_r, is_q_r);
			is_p |= is_p_r; is_q |= is_q_r;
			if(res) return res;
			else if(is_p&&is_q) return root;
			// return
			return NULL;
		}
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			bool is_p, is_q;
			return lowestCommonAncestor(root, p, q, is_p, is_q);
		}
};
