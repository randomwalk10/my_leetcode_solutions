/*
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> res;
		stack<TreeNode*> s_p1, s_p2;
		stack<bool> s_v1, s_v2;

		if(root1){
			s_p1.push(root1); s_v1.push(false);
		}
		if(root2){
			s_p2.push(root2); s_v2.push(false);
		}
		while( (!s_p1.empty())||(!s_p2.empty()) ){
			// get the next element
			if(!s_p1.empty()){
				while(!s_v1.top()){
					TreeNode* tmp = s_p1.top(); s_p1.pop();
					s_v1.pop();
					// right
					if(tmp->right){
						s_p1.push(tmp->right);
						s_v1.push(false);
					}
					// self
					s_p1.push(tmp);
					s_v1.push(true);
					// left
					if(tmp->left){
						s_p1.push(tmp->left);
						s_v1.push(false);
					}
				}
			}
			if(!s_p2.empty()){
				while(!s_v2.top()){
					TreeNode* tmp = s_p2.top(); s_p2.pop();
					s_v2.pop();
					// right
					if(tmp->right){
						s_p2.push(tmp->right);
						s_v2.push(false);
					}
					// self
					s_p2.push(tmp);
					s_v2.push(true);
					// left
					if(tmp->left){
						s_p2.push(tmp->left);
						s_v2.push(false);
					}
				}
			}

			// compare
			if(s_p1.empty()){
				res.push_back(s_p2.top()->val);
				s_p2.pop(); s_v2.pop();
			}
			else if(s_p2.empty()){
				res.push_back(s_p1.top()->val);
				s_p1.pop(); s_v1.pop();
			}
			else if(s_p1.top()->val<=s_p2.top()->val){
				res.push_back(s_p1.top()->val);
				s_p1.pop(); s_v1.pop();
			}
			else{
				res.push_back(s_p2.top()->val);
				s_p2.pop(); s_v2.pop();
			}
		}

		return res;
    }
};
