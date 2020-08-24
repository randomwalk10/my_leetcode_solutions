/*
Given a binary tree with the following rules:

root.val == 0
If treeNode.val == x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
If treeNode.val == x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

You need to first recover the binary tree and then implement the FindElements class:

FindElements(TreeNode* root) Initializes the object with a contamined binary tree, you need to recover it first.
bool find(int target) Return if the target value exists in the recovered binary tree.
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-elements-in-a-contaminated-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements {
private:
	TreeNode* _root;
	unordered_set<int> _vals;
public:
    FindElements(TreeNode* root) {
		_root = root;
		stack<TreeNode*> s;
		stack<int> s_v;

		if(_root){
			_root->val = 0;
			s.push(_root);
			s_v.push(0);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int tmp_val = s_v.top(); s_v.pop();
			_vals.insert(tmp_val);
			
			// left
			if(tmp->left){
				s.push(tmp->left);
				s_v.push(tmp_val*2+1);
			}
			// right
			if(tmp->right){
				s.push(tmp->right);
				s_v.push(tmp_val*2+2);
			}
		}
    }

    bool find(int target) {
		return (_vals.find(target)!=_vals.end());
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
