/*
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest.  You may return the result in any order.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-nodes-and-return-forest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		vector<TreeNode*> res;
		stack<TreeNode*> s, s_p;
		unordered_set<int> td;

		for (int i = 0; i < (int)to_delete.size(); ++i) {
			td.insert(to_delete[i]);
		}

		if(root){
			s.push(root);
			s_p.push(NULL);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			TreeNode* tmp_p = s_p.top(); s_p.pop();

			if(td.end()!=td.find(tmp->val)){
				if(tmp_p){
					if(tmp_p->left==tmp){
						tmp_p->left = NULL;
					}
					else{
						tmp_p->right = NULL;
					}
				}
				if(tmp->right){
					s.push(tmp->right);
					s_p.push(NULL);
				}
				if(tmp->left){
					s.push(tmp->left);
					s_p.push(NULL);
				}
			}
			else{
				if(NULL==tmp_p){
					res.push_back(tmp);
				}
				if(tmp->right){
					s.push(tmp->right);
					s_p.push(tmp);
				}
				if(tmp->left){
					s.push(tmp->left);
					s_p.push(tmp);
				}
			}
		}

		return res;
    }
};
