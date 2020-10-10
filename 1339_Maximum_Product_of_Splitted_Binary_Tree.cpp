/*
Given a binary tree root. Split the binary tree into two subtrees by removing 1 edge such that the product of the sums of the subtrees are maximized.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:



Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
Example 2:



Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation:  Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
Example 3:

Input: root = [2,3,9,10,7,8,6,5,4,11,1]
Output: 1025
Example 4:

Input: root = [1,1]
Output: 1
 

Constraints:

Each tree has at most 50000 nodes and at least 2 nodes.
Each node's value is between [1, 10000].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-splitted-binary-tree
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
    int maxProduct(TreeNode* root) {
		stack<TreeNode*> s;
		long long total_sum = 0;
		long long res = 0;

		if(root) s.push(root);
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			total_sum += tmp->val;

			if(tmp->right) s.push(tmp->right);
			if(tmp->left) s.push(tmp->left);
		}

		stack<bool> s_v;
		if(root){
			s.push(root);
			s_v.push(false);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			bool visited = s_v.top(); s_v.pop();

			if(visited){
				tmp->val += (tmp->left)?tmp->left->val:0;
				tmp->val += (tmp->right)?tmp->right->val:0;
				long long tmp_product = (total_sum-tmp->val)*tmp->val;
				res = (tmp_product>res)?tmp_product:res;
			}
			else{
				//self
				s.push(tmp);
				s_v.push(true);
				//right
				if(tmp->right){
					s.push(tmp->right);
					s_v.push(false);
				}
				//left
				if(tmp->left){
					s.push(tmp->left);
					s_v.push(false);
				}
			}
		}

		return res % (1000000000+7);
    }
};
