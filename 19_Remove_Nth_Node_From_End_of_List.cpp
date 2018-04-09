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

#include <queue>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		queue<ListNode*> past_nodes;
		for(int i=0; i<(n+1); ++i) past_nodes.push(NULL);
		ListNode* temp = head;
		while(temp){
			past_nodes.push(temp);
			past_nodes.pop();
			temp = temp->next;
		}
		if(past_nodes.front()==NULL){
			return head->next;
		}
		else{
			ListNode* prev_node = past_nodes.front();
			ListNode* temp_node = prev_node->next;
			prev_node->next = prev_node->next->next;
			delete temp_node;
		}
		return head;
    }
};
