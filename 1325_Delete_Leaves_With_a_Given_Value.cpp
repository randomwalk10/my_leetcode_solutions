/*
Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if it's parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you can't).

Constraints:

1 <= target <= 1000
The given binary tree will have between 1 and 3000 nodes.
Each node's value is between [1, 1000].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-leaves-with-a-given-value
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
		if(NULL==root) return NULL;
		stack<TreeNode*> s, s_p;
		stack<bool> s_v;
		TreeNode* res = NULL;

		s.push(root);
		s_p.push(NULL);
		s_v.push(false);
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			TreeNode* tmp_p = s_p.top(); s_p.pop();
			bool is_visited = s_v.top(); s_v.pop();

			if(is_visited){
				if((tmp->left==NULL)&&(tmp->right==NULL)&&(tmp->val==target)){
					if(tmp_p!=NULL){
						if(tmp_p->left==tmp) tmp_p->left = NULL;
						else tmp_p->right = NULL;
					}
					else res = NULL;
					// delete tmp;
				}
				else{
					if(tmp_p==NULL) res = tmp;
				}
			}
			else{
				// self
				s.push(tmp);
				s_p.push(tmp_p);
				s_v.push(true);
				// right
				if(tmp->right){
					s.push(tmp->right);
					s_p.push(tmp);
					s_v.push(false);
				}
				// left
				if(tmp->left){
					s.push(tmp->left);
					s_p.push(tmp);
					s_v.push(false);
				}
			}
		}

		return res;
    }
};
