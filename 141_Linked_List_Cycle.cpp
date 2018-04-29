/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

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
    bool hasCycle(ListNode *head) {
		if(NULL==head) return false;
		ListNode* pt1 = head;
		ListNode* pt2 = head->next;

		while( pt1 && pt2 ){
			if(pt1==pt2) return true;
			pt1 = pt1->next;
			if(pt2->next) pt2 = pt2->next->next;
			else return false;
		}

		return false;
    }
};
