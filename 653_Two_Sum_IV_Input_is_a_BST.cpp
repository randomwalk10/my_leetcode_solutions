/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
 

Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
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
    bool findTarget(TreeNode* root, int k) {
		if(NULL==root) return false;
		vector<int> vals;

		stack<TreeNode*> s_parent;
		stack<bool> s_visited;
		s_parent.push(root);
		s_visited.push(false);
		while(!s_parent.empty()){
			TreeNode* tmp_node = s_parent.top(); s_parent.pop();
			bool tmp_visited = s_visited.top(); s_visited.pop();
			if(tmp_visited){
				vals.push_back(tmp_node->val);
			}
			else{
				//right
				if(tmp_node->right){
					s_parent.push(tmp_node->right);
					s_visited.push(false);
				}
				//self
				s_parent.push(tmp_node);
				s_visited.push(true);
				//left
				if(tmp_node->left){
					s_parent.push(tmp_node->left);
					s_visited.push(false);
				}
			}
		}
		if(vals.size()<2) return false;

		int l = 0;
		int r = vals.size() - 1;
		while(l<r){
			int tmp_left = vals[l];
			int tmp_right = vals[r];
			if(tmp_left+tmp_right>k){
				--r;
			}
			else if(tmp_left+tmp_right<k){
				++l;
			}
			else return true;
		}

		return false;
    }
};
