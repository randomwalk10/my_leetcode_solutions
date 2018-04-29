/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) {
		if(NULL==head) return NULL;
		int idx = 2;
		ListNode* r = head->next;
		ListNode* odd_end = head;
		ListNode* prev_r = head;

		while(r){
			if(idx&0x1){//odd
				//reconnect
				ListNode *temp = odd_end->next;
				odd_end->next = r;
				prev_r->next = r->next;
				r->next = temp;
				//update
				odd_end = r;
				r = prev_r->next;
			}
			else{//even
				prev_r = r;
				r = r->next;
			}
			idx++;
		}

		return head;
    }
};
