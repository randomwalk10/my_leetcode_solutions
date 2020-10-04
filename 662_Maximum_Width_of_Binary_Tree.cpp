/*
Given a binary tree, write a function to get the maximum width of the given tree. The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
 

Constraints:

The given binary tree will have between 1 and 3000 nodes.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-width-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
#include <vector>
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
    int widthOfBinaryTree(TreeNode* root) {
		stack<TreeNode*> s;
		stack<int> s_d;
		stack<unsigned long long> s_w;
		vector<unsigned long long> d_l;
		unsigned long long res = 0;

		if (root) {
			s.push(root);
			s_d.push(0);
			s_w.push(0);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int d = s_d.top(); s_d.pop();
			unsigned long long w = s_w.top(); s_w.pop();
			if(d>=d_l.size()){
				d_l.push_back(w);
			}
			res = (w-d_l[d]+1>res)?w-d_l[d]+1:res;

			//right
			if(tmp->right){
				s.push(tmp->right);
				s_d.push(d+1);
				s_w.push(2*w+1);
			}
			//left
			if(tmp->left){
				s.push(tmp->left);
				s_d.push(d+1);
				s_w.push(2*w);
			}
		}

		return res;
    }
};
