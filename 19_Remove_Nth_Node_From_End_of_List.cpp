/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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

#include <stack>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		stack<ListNode*> node_s;
		//push all nodes into stack
		ListNode* temp = head;
		while(temp){
			node_s.push(temp);
			temp = temp->next;
		}
		//trace back to nth order backwards
		for(int i=0; i<n; ++i){
			temp = node_s.top();
			node_s.pop();
		}
		//reconnect
		if(node_s.empty()) head = temp->next;
		else node_s.top()->next = temp->next;
		delete temp;
		//return
		return head;
    }
};
