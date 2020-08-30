/*
Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pseudo-palindromic-paths-in-a-binary-tree
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
    int pseudoPalindromicPaths (TreeNode* root) {
		stack<TreeNode*> s;
		stack<int> s_xor;
		int res = 0;

		if(root){
			s.push(root);
			s_xor.push(0);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int prev_xor = s_xor.top(); s_xor.pop();

			int cur_xor = prev_xor ^ (1<<(tmp->val-1));
			if((NULL==tmp->left)&&(NULL==tmp->right)){
				if(cur_xor==0) ++res;
				else{
					for (int i = 1; i < 10; ++i) {
						if(cur_xor==(1<<(i-1))){
							++res;
							break;
						}
					}
				}
				continue;
			}

			if(tmp->right){
				s.push(tmp->right);
				s_xor.push(cur_xor);
			}
			if(tmp->left){
				s.push(tmp->left);
				s_xor.push(cur_xor);
			}
		}

		return res;
    }
};
