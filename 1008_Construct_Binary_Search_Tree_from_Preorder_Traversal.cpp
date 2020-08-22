/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
		if(preorder.empty()) return NULL;
		TreeNode* res = new TreeNode(preorder[0]);
		stack<TreeNode*> s_parent;

		s_parent.push(res);
		for (int i = 1; i < preorder.size(); ++i) {
			if(s_parent.top()->val>preorder[i]){
				s_parent.top()->left = new TreeNode(preorder[i]);
				s_parent.push(s_parent.top()->left);
			}
			else{
				TreeNode* tmp = NULL;
				while((s_parent.empty()==false)&&(s_parent.top()->val<preorder[i])){
					tmp = s_parent.top(); s_parent.pop();
				}
				tmp->right = new TreeNode(preorder[i]);
				s_parent.push(tmp->right);
			}
		}

		return res;
    }
};
