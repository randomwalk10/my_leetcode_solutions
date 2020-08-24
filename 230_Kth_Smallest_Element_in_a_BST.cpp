/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

 

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

 

Constraints:

The number of elements of the BST is between 1 to 10^4.
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> s;
		stack<bool> s_v;
		int res;

		s.push(root);
		s_v.push(false);
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			bool is_visited = s_v.top(); s_v.pop();

			if(is_visited){
				res = tmp->val;
				--k;
				if(k==0) break;
			}
			else{
				// right
				if(tmp->right){
					s.push(tmp->right);
					s_v.push(false);
				}
				// self
				s.push(tmp);
				s_v.push(true);
				// left
				if(tmp->left){
					s.push(tmp->left);
					s_v.push(false);
				}
			}
		}

		return res;
    }
};
