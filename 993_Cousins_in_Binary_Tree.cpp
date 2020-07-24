/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cousins-in-binary-tree
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
    bool isCousins(TreeNode* root, int x, int y) {
		if(NULL==root) return false;
		stack<TreeNode*> st;
		stack<TreeNode*> sp;
		stack<int> sd;
		int dx=-1, dy=-1;
		TreeNode *px=NULL, *py=NULL;
		
		st.push(root);
		sp.push(NULL);
		sd.push(1);
		while(!st.empty()){
			TreeNode* tmp = st.top(); st.pop();
			TreeNode* parent = sp.top(); sp.pop();
			int d = sd.top(); sd.pop();

			if(tmp->val==x){
				dx = d;
				px = parent;
			}
			else if(tmp->val==y){
				dy = d;
				py = parent;
			}
			if((dx>0)&&(dy>0)){
				if((dx!=dy)||(px==py)) return false;
				else return true;
			}

			if(tmp->left){
				st.push(tmp->left);
				sp.push(tmp);
				sd.push(d+1);
			}
			if(tmp->right){
				st.push(tmp->right);
				sp.push(tmp);
				sd.push(d+1);
			}
		}

		return false;
    }
};
