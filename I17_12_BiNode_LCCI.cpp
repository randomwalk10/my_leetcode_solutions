/*
The data structure TreeNode is used for binary tree, but it can also used to represent a single linked list (where left is null, and right is the next node in the list). Implement a method to convert a binary search tree (implemented with TreeNode) into a single linked list. The values should be kept in order and the operation should be performed in place (that is, on the original data structure).

Return the head node of the linked list after converting.

Note: This problem is slightly different from the original one in the book.

 

Example:

Input:  [4,2,5,1,3,null,6,0]
Output:  [0,null,1,null,2,null,3,null,4,null,5,null,6]
Note:

The number of nodes will not exceed 100000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binode-lcci
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
    TreeNode* convertBiNode(TreeNode* root) {
		TreeNode* res = NULL;
		if(NULL==root) return res;

		stack<TreeNode*> s_parent;
		stack<bool> s_visited;
		TreeNode* tail = NULL;

		s_parent.push(root);
		s_visited.push(false);
		while(!s_parent.empty()){
			TreeNode* tmp_node = s_parent.top(); s_parent.pop();
			bool tmp_visited = s_visited.top(); s_visited.pop();
			if(tmp_visited){
				if(res==NULL){
					res = tmp_node; // head
					tail = tmp_node;
				}
				else{
					tail->right = tmp_node;
					tail = tmp_node;
				}
				tail->left = NULL;
			}
			else{
				//right
				if(tmp_node->right){
					s_parent.push(tmp_node->right);
					s_visited.push(false);
				}
				//self
				s_parent.push(tmp_node);
				s_visited.push(true);
				//left
				if(tmp_node->left){
					s_parent.push(tmp_node->left);
					s_visited.push(false);
				}
			}
		}
		
		return res;
    }
};
