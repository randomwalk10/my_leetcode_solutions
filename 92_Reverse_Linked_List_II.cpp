/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
		if(m==n) return head;
		ListNode *prev_l = NULL, *l;
		ListNode *prev_r, *r;
		l = head;
		//find node #m
		for(int i = 1; i<m; ++i){
			prev_l = l;
			l = l->next;
		}
		r = l->next;
		prev_r = l;
			
		//reverse until node #n
		for(int i = 1; i<=(n-m); ++i){
			//reconnect
			if(prev_l) prev_l->next = r;
			prev_r->next = r->next;
			r->next = l;
			//update
			l = r;
			r = prev_r->next;
		}
	
		//return
		if(1!=m) return head;
		return l;
    }
};
