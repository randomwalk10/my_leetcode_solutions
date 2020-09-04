/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
		stack<TreeNode*> s;
		stack<bool> s_v;
		unordered_map<TreeNode*, int> m_robbed;
		unordered_map<TreeNode*, int> m_spared;
		int res = 0;

		if(root){
			s.push(root);
			s_v.push(false);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			bool visited = s_v.top(); s_v.pop();

			if(visited){
				int sum1 = tmp->val;
				if(tmp->left){
					sum1 += m_spared[tmp->left];
				}
				if(tmp->right){
					sum1 += m_spared[tmp->right];
				}
				m_robbed[tmp] = sum1;

				int sum2 = 0;
				if(tmp->left){
					if(m_spared[tmp->left]>m_robbed[tmp->left])
						sum2 += m_spared[tmp->left];
					else
						sum2 += m_robbed[tmp->left];
				}
				if(tmp->right){
					if(m_spared[tmp->right]>m_robbed[tmp->right])
						sum2 += m_spared[tmp->right];
					else
						sum2 += m_robbed[tmp->right];
				}
				m_spared[tmp] = sum2;

				res = (sum1>sum2)?sum1:sum2;
			}
			else{
				//post order
				s.push(tmp);
				s_v.push(true);
				if(tmp->right){
					s.push(tmp->right);
					s_v.push(false);
				}
				if(tmp->left){
					s.push(tmp->left);
					s_v.push(false);
				}
			}
		}

		return res;
    }
};
