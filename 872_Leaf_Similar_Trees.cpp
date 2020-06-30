/*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Constraints:

Both of the given trees will have between 1 and 200 nodes.
Both of the given trees will have values between 0 and 200

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/leaf-similar-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void leafSimilar(TreeNode* root, vector<int>& res){
		if(root==NULL) return;
		stack<TreeNode*> s;

		s.push(root);
		while(!s.empty()){
			TreeNode* tmp_node = s.top(); s.pop();
			if((tmp_node->left==NULL)&&(tmp_node->right==NULL)) res.push_back(tmp_node->val);
			if(tmp_node->right) s.push(tmp_node->right);
			if(tmp_node->left) s.push(tmp_node->left);
		}

		return;
	}
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> res1, res2;
		leafSimilar(root1, res1);
		leafSimilar(root2, res2);

		if(res1.size()!=res2.size()) return false;
		for (int i = 0; i < (int)res1.size(); ++i) {
			if(res1[i]!=res2[i]) return false;
		}
		return true;
    }
};
