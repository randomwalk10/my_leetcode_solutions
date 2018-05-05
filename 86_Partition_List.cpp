/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
		ListNode* l = NULL;
		ListNode* r = NULL;
		ListNode* output = NULL;

		while(head){
			//check val
			if(head->val>=x){
				if(output){
					r->next = new ListNode(head->val);
					r = r->next;
				}
				else{
					output = new ListNode(head->val);
					r = output;
				}
			}
			else{
				if(output){
					if(l){
						ListNode* temp = l->next;
						l->next = new ListNode(head->val);
						if(l==r) r = l->next;
						l = l->next;
						l->next = temp;
					}
					else{
						l = new ListNode(head->val);
						l->next = output;
						output = l;
					}
				}
				else{
					output = new ListNode(head->val);
					l = output;
					r = output;
				}
			}
			//update
			head = head->next;
		}

		return output;
    }
};
