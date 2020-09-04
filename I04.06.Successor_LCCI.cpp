/*
Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree.

Return null if there's no "next" node for the given node.

Example 1:

Input: root = [2,1,3], p = 1

  2
 / \
1   3

Output: 2
Example 2:

Input: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /   
1

Output: null

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/successor-lcci
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		stack<TreeNode*> s;
		stack<bool> s_v;
		TreeNode* res = NULL;
		bool found = false;

		if(root){
			s.push(root);
			s_v.push(false);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			bool visited = s_v.top(); s_v.pop();

			if(visited){
				if(found){
					res = tmp;
					break;
				}
			}
			else{
				if(tmp->val==p->val){
					found=true;
					if(tmp->right){
						s.push(tmp->right);
						s_v.push(false);
					}
				}
				else{
					if(tmp->val>p->val){
						s.push(tmp);
						s_v.push(true);
						if(tmp->left){
							s.push(tmp->left);
							s_v.push(false);
						}
					}
					else{
						if(tmp->right){
							s.push(tmp->right);
							s_v.push(false);
						}
					}
				}
			}
		}

		return res;
    }
};
