/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
		int prev_val;
		bool skipOn = false;
		ListNode* output = NULL;
		ListNode* temp = output;
		
		while(head){
			if(skipOn){
				if(head->val!=prev_val) skipOn = false;
				else head = head->next;
			}
			else if( (head->next)&&(head->val==head->next->val) ){
				prev_val = head->val;
				skipOn = true;
				head = head->next->next;
			}
			else{
				if(output){
					temp->next = new ListNode(head->val);
					temp = temp->next;
				}
				else{
					temp = new ListNode(head->val);
					output = temp;
				}
				head = head->next;
			}
		}

		return output;
    }
};
