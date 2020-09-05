/*
Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is tree consisting of that node, plus the set of all descendants of that node.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-subtree-with-all-the-deepest-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
#include <unordered_map>
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		int max_d = -1;
		int max_cnt = 0;
		TreeNode* res = NULL;
		stack<TreeNode*> s;
		stack<bool> s_v;
		stack<int> s_d;

		if(root){
			s.push(root);
			s_d.push(0);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int d = s_d.top(); s_d.pop();

			if(d>max_d){
				max_d = d;
				max_cnt = 1;
			}
			else if(d==max_d){
				max_cnt += 1;
			}

			if(tmp->right){
				s.push(tmp->right);
				s_d.push(d+1);
			}
			if(tmp->left){
				s.push(tmp->left);
				s_d.push(d+1);
			}
		}

		unordered_map<TreeNode*, int> m_cnt;
		if(root){
			s.push(root);
			s_v.push(false);
			s_d.push(0);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int d = s_d.top(); s_d.pop();
			bool visited = s_v.top(); s_v.pop();

			if(visited){
				if(d==max_d){
					m_cnt[tmp] = 1;
				}
				else{
					m_cnt[tmp] = 0;
					if(tmp->left){
						m_cnt[tmp] += m_cnt[tmp->left];
					}
					if(tmp->right){
						m_cnt[tmp] += m_cnt[tmp->right];
					}
				}
				if(m_cnt[tmp]==max_cnt){
					res = tmp;
					break;
				}
			}
			else{
				s.push(tmp);
				s_d.push(d);
				s_v.push(true);
				if(tmp->right){
					s.push(tmp->right);
					s_d.push(d+1);
					s_v.push(false);
				}
				if(tmp->left){
					s.push(tmp->left);
					s_d.push(d+1);
					s_v.push(false);
				}
			}
		}

		return res;
    }
};
