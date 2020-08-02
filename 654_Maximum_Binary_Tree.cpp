/*
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
Note:
The size of the given array will be in the range [1,1000].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-binary-tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		TreeNode* res = NULL;
		if(nums.empty()) return res;
		stack<TreeNode*> s_parent;
		stack<int> s_l;
		stack<int> s_r;
		stack<bool> s_left;

		s_parent.push(NULL);
		s_l.push(0);
		s_r.push(nums.size()-1);
		s_left.push(false);
		while(!s_parent.empty()){
			TreeNode* tmp = s_parent.top(); s_parent.pop();
			int l = s_l.top(); s_l.pop();
			int r = s_r.top(); s_r.pop();
			bool is_left = s_left.top(); s_left.pop();
			int max_i = l;

			for(int i=l; i<=r; ++i){
				if(nums[max_i]<nums[i]) max_i = i;
			}

			TreeNode* cur_node = new TreeNode(nums[max_i]);
			if(tmp==NULL) res = cur_node;
			else if(is_left){
				tmp->left = cur_node;
			}
			else{
				tmp->right = cur_node;
			}

			if(l<max_i){
				s_parent.push(cur_node);
				s_l.push(l);
				s_r.push(max_i-1);
				s_left.push(true);
			}
			if(r>max_i){
				s_parent.push(cur_node);
				s_l.push(max_i+1);
				s_r.push(r);
				s_left.push(false);
			}
		}

		return res;
    }
};
