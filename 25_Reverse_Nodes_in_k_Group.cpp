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
#include <vector>
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
		ListNode* temp = head;
		vector<ListNode*> saved_nodes;
		//transverse k nodes
		for(int i=0; i<k; ++i){
			if(temp){
				saved_nodes.push_back(temp);
				temp = temp->next;
			}
			else return head;
		}
		//reverse k nodes
		for(int i=0; i<k-1; ++i){
			int idx = k-1-i;
			saved_nodes[idx]->next = saved_nodes[idx-1];
		}
		//append remaining nodes
		saved_nodes[0]->next = reverseKGroup(temp, k);
		//return
		return saved_nodes[k-1];
    }
};
