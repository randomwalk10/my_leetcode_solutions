/*
Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0 represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically smaller than "aba".  A leaf of a node is a node that has no children.)

 

Example 1:



Input: [0,1,2,3,4,3,4]
Output: "dba"
Example 2:



Input: [25,1,3,1,3,0,2]
Output: "adz"
Example 3:



Input: [2,2,1,null,1,0,null,0]
Output: "abc"
 

Note:

The number of nodes in the given tree will be between 1 and 8500.
Each node in the tree will have a value between 0 and 25.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-string-starting-from-leaf
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
		stack<TreeNode*> s;
		stack<bool> s_v;
		vector<int> p;
		vector<int> small_p;
		string res;

		if(root){
			s.push(root);
			s_v.push(false);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			bool visited = s_v.top(); s_v.pop();

			if(visited){
				p.pop_back();
			}
			else{
				p.push_back(tmp->val);

				if((NULL==tmp->left)&&(NULL==tmp->right)){
					if(small_p.empty()) small_p = p;
					else{
						bool replace_flag = (p.size()<small_p.size());
						int i=p.size()-1, j=small_p.size()-1;
						while((i>=0)&&(j>=0)){
							if(p[i]<small_p[j]){
								replace_flag = true;
								break;
							}
							else if(p[i]>small_p[j]){
								replace_flag = false;
								break;
							}
							--i; --j;
						}
						if(replace_flag) small_p = p;
					}
				}

				s.push(tmp);
				s_v.push(true);
				if(tmp->right){
					s.push(tmp->right);
					s_v.push(false);
				}
				if(tmp->left){
					s.push(tmp->left);
					s_v.push(false);
				}
			}
		}

		for (int i = (int)small_p.size()-1; i >=0; --i) {
			res.push_back('a'+small_p[i]);
		}

		return res;
    }
};
