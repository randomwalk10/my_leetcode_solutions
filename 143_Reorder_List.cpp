/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
		stack<ListNode*> ls;

		//get stack
		ListNode* temp = head;
		while(temp){
			ls.push(temp);
			temp = temp->next;
		}

		//reorder
		temp = head;
		while( temp && (temp->next) && (temp->next->next) ){
			//reconnect
			ListNode* backup = temp->next;
			temp->next = ls.top();
			ls.top()->next = backup;
			//update
			ls.pop();
			ls.top()->next = NULL;
			temp = temp->next->next;
		}
    }
};
