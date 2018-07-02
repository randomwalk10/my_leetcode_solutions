/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees
of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define NULL 0
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*time complexity: O(N), space complexity: O(1)*/
class Solution {
private:
	TreeNode* sortedListToBST(ListNode* head, int list_len, ListNode** next_ptr){
		*next_ptr = NULL;
		if((head==NULL)||(0==list_len)) return NULL;
		if(list_len<2){
			*next_ptr = head->next;
			return new TreeNode(head->val);
		}
		//convert the left and right into trees
		//find the mid node
		//attach them to mid node
		int half_len = list_len/2;
		ListNode *l_next;
		TreeNode *tree_l;
		tree_l = sortedListToBST(head, half_len, &l_next);
		if(l_next==NULL) return tree_l;
		TreeNode* out = new TreeNode(l_next->val);
		out->left = tree_l;
		out->right = sortedListToBST(l_next->next, list_len-1-half_len, next_ptr);
		if(out->right==NULL) *next_ptr = l_next->next;
		//return
		return out;
	}
public:
    TreeNode* sortedListToBST(ListNode* head) {
		//check the length of lined list
		ListNode* temp = head;
		int list_len = 0;
		while(temp){
			list_len++;
			temp = temp->next;
		}
		//perform conversion
		ListNode* next;
		return sortedListToBST(head, list_len, &next);
    }
};
