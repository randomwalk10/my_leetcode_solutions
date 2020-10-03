/*
Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

 

Example 1:



Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.  
Example 2:



Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Example 3:

Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.
 

Constraints:

1 <= node.val <= 100 for each node in the linked list and binary tree.
The given linked list will contain between 1 and 100 nodes.
The given binary tree will contain between 1 and 2500 nodes.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-in-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool isSubPath(ListNode* head, TreeNode* root) {
		stack<TreeNode*> s_t;
		stack<ListNode*> s_l;

		s_t.push(root);
		while(!s_t.empty()){
			TreeNode* tmp = s_t.top(); s_t.pop();

			if(tmp->val==head->val){
				s_l.push(head);
				s_t.push(tmp);
				while(!s_l.empty()){
					ListNode* tmp_l = s_l.top(); s_l.pop();
					TreeNode* tmp_t = s_t.top(); s_t.pop();

					if(tmp_l->val!=tmp_t->val) continue;

					if(NULL==tmp_l->next){
						return true;
					}
					if(NULL!=tmp_t->right){
						s_l.push(tmp_l->next);
						s_t.push(tmp_t->right);
					}
					if(NULL!=tmp_t->left){
						s_l.push(tmp_l->next);
						s_t.push(tmp_t->left);
					}
				}
			}

			if(tmp->right){
				s_t.push(tmp->right);
			}
			if(tmp->left){
				s_t.push(tmp->left);
			}
		}

		return false;
    }
};
