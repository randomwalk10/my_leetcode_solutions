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

#include <vector>
using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
		if( (head==NULL)||(k<=0) ) return head;
		vector<ListNode *> node_vector;
		ListNode* temp = head;
		int node_len = 0;

		do{
			node_vector.push_back(temp);
			temp = temp->next;
			node_len++;
		}while(temp);

		for(int i=0; i<k%node_len; ++i){
			node_vector.back()->next = node_vector.front();
			node_vector.insert(node_vector.begin(), node_vector.back());
			node_vector.pop_back();
			node_vector.back()->next = NULL;
		}

		return *node_vector.begin();
    }
};
