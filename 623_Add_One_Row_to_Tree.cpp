/*
Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root node is at depth 1.

The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, create two tree nodes with value v as N's left subtree root and right subtree root. And N's original left subtree should be the left subtree of the new left subtree root, its original right subtree should be the right subtree of the new right subtree root. If depth d is 1 that means there is no depth d-1 at all, then create a tree node with value v as the new root of the whole original tree, and the original tree is the new root's left subtree.

Example 1:
Input: 
A binary tree as following:
       4
     /   \
    2     6
   / \   / 
  3   1 5   

v = 1

d = 2

Output: 
       4
      / \
     1   1
    /     \
   2       6
  / \     / 
 3   1   5   

Example 2:
Input: 
A binary tree as following:
      4
     /   
    2    
   / \   
  3   1    

v = 1

d = 3

Output: 
      4
     /   
    2
   / \    
  1   1
 /     \  
3       1
Note:
The given d is in range [1, maximum depth of the given tree + 1].
The given binary tree has at least one tree node.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-one-row-to-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if(d==1){
			TreeNode* res = new TreeNode(v);
			res->left = root;
			return res;
		}

		stack<TreeNode*> s;
		stack<int> s_d;
		s.push(root);
		s_d.push(1);
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int tmp_d = s_d.top(); s_d.pop();

			if(tmp_d==(d-1)){
				TreeNode* tmp_l = new TreeNode(v);
				if(tmp->left){
					tmp_l->left = tmp->left;
				}
				tmp->left = tmp_l;

				TreeNode* tmp_r = new TreeNode(v);
				if(tmp->right){
					tmp_r->right = tmp->right;
				}
				tmp->right = tmp_r;
				continue;
			}

			if(tmp->right){
				s.push(tmp->right);
				s_d.push(tmp_d+1);
			}
			if(tmp->left){
				s.push(tmp->left);
				s_d.push(tmp_d+1);
			}
		}

		return root;
    }
};
