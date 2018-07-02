/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
	ListNode* mergeTwoSortedList(ListNode* a, ListNode* b){
		ListNode* out = NULL;
		ListNode* temp = out;
		bool exitFlag = false;

		while( ((NULL!=a) || (NULL!=b)) && \
				(false==exitFlag) ){
			ListNode* temp2 = NULL;
			//compare
			if(NULL==a){
				temp2 = b;
				b = b->next;
				exitFlag = true;
			}
			else if(NULL==b){
				temp2 = a;
				a = a->next;
				exitFlag = true;
			}
			else{
				if(a->val<b->val){
					temp2 = a;
					a = a->next;
				}
				else{
					temp2 = b;
					b = b->next;
				}
			}
			//update
			if(out==NULL){
				out = temp2;
				temp = temp2;
			}
			else{
				temp->next = temp2;
				temp = temp2;
			}	
		}

		return out;
	}

    ListNode* sortList(ListNode* head) {
		ListNode* output = NULL;
		//determine the length N of list
		int list_len = 0;
		ListNode* temp = head;
		while(temp){
			list_len++;
			temp = temp->next;
		}
		if(list_len<2) return head;
		//break the linked list into halves
		int half_len = list_len/2;
		ListNode* l_head = head;
		ListNode* r_head = head;
		for(int i=0; i<(half_len-1); ++i){
			r_head = r_head->next;
		}
		temp = r_head->next;
		r_head->next = NULL;
		r_head = temp;

		//and sort them
		l_head = sortList(l_head);
		r_head = sortList(r_head);
		
		//merge the two sored linked list
		output = mergeTwoSortedList(l_head, r_head);

		//return
		return output;
    }
};
