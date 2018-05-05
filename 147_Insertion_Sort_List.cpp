/*
Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.
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
	ListNode* insertVal(ListNode* input, int val){
		ListNode* output = input;
		ListNode* last_smaller_node = NULL;
		while(input){
			//check value
			if(val<=input->val) break;
			else last_smaller_node = input;
			//update
			input = input->next;
		}
		if(last_smaller_node){
			ListNode* temp = last_smaller_node->next;
			last_smaller_node->next = new ListNode(val);
			last_smaller_node->next->next = temp;
		}
		else if(output){
			ListNode* temp = output;
			output = new ListNode(val);
			output->next = temp;
		}
		else output = new ListNode(val);
		return output;
	}

    ListNode* insertionSortList(ListNode* head) {
		ListNode* output = NULL;

		while(head){
			output = insertVal(output, head->val);
			head = head->next;
		}

		return output;
    }
};
