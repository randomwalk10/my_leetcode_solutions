/*
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* temp1 = l1;
		ListNode* temp2 = l2;
		ListNode* result = new ListNode(0);
		ListNode* tempr = result;
		int carry = 0;
		while(temp1 || temp2 || carry){
			int new_val = carry + ( (temp1) ? temp1->val : 0 ) + ( (temp2) ? temp2->val : 0 );
			carry = new_val / 10;
			new_val = new_val % 10;
			ListNode* new_digit = new ListNode(new_val);
			tempr->next = new_digit;
			tempr = tempr->next;
			temp1 = (temp1) ? temp1->next : temp1;
			temp2 = (temp2) ? temp2->next : temp2;
		}
		return result->next;
    }
};
