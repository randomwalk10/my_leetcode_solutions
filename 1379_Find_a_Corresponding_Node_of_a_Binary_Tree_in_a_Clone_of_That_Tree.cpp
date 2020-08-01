/*
Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

Follow up: Solve the problem if repeated values on the tree are allowed.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
		stack<TreeNode*> so, sc;

		so.push(original);
		sc.push(cloned);
		while(!so.empty()){
			TreeNode* tmp_o = so.top(); so.pop();
			TreeNode* tmp_c = sc.top(); sc.pop();

			if(tmp_o==target) return tmp_c;

			if(tmp_o->right){
				so.push(tmp_o->right);
				sc.push(tmp_c->right);
			}
			if(tmp_o->left){
				so.push(tmp_o->left);
				sc.push(tmp_c->left);
			}
		}

		return NULL;
    }
};
