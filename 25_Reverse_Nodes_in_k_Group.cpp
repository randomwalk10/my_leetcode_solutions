/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		if(k<=1) return head;
		ListNode* out = head;
		//count the length
		int len = 0;
		ListNode* temp = head;
		while(temp){
			temp = temp->next;
			len++;
		}
		//compute the number of segments
		int segs = len/k;
		//perform reversing of each segments
		ListNode* prev_tail = NULL;
		ListNode* cur_ptr = head;
		ListNode* prev_ptr = NULL;
		for(int i=0; i<segs; ++i){
			//reverse
			ListNode* temp_tail = cur_ptr;
			for(int j=0; j<k; ++j){
				ListNode* temp_ptr = cur_ptr->next;
				cur_ptr->next = prev_ptr;
				prev_ptr = cur_ptr;
				cur_ptr = temp_ptr;
			}
			//reconnect and update
			if(prev_tail) prev_tail->next = prev_ptr;
			else out = prev_ptr;
			temp_tail->next = cur_ptr;
			prev_tail = temp_tail;
		}
		//return
		return out;
    }
};
