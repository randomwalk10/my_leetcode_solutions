/*
Given a list, rotate the list to the right by k places, where k is non-negative.


Example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
		if( (head==NULL)||(k<=0) ) return head;
		stack<ListNode *> node_s;
		ListNode* temp = head;
		int node_len = 0;

		while(temp){
			node_s.push(temp);
			temp = temp->next;
			node_len++;
		};

		ListNode* tail = node_s.top();
		ListNode* cut = head;
		for(int i=0; i<k%node_len; ++i){
			cut = node_s.top();
			node_s.pop();
		}

		if(k%node_len){
			node_s.top()->next = NULL;
			tail->next = head;
		}

		return cut;
    }
};
