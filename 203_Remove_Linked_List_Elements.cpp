/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define NULL 0
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		if(NULL==head) return NULL;
		ListNode* temp_head = head;
		ListNode* prev_node = NULL;
		ListNode* temp_node = head;
		while(temp_node){
			if(temp_node->val==val){
				if(temp_node==temp_head){
					temp_head = temp_node->next;
					delete temp_node;
					temp_node = temp_head;
				}
				else{
					prev_node->next = temp_node->next;
					delete temp_node;
					temp_node = prev_node->next;
				}
			}
			else{
				prev_node = temp_node;
				temp_node = temp_node->next;
			}
		}
		return temp_head;
    }
};
