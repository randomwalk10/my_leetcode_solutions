/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> val_s1;
		stack<int> val_s2;
		while(l1){
			val_s1.push(l1->val);
			l1 = l1->next;
		}
		while(l2){
			val_s2.push(l2->val);
			l2 = l2->next;
		}
		int carry = 0;
		ListNode* output = NULL;

		while( (!val_s1.empty()) || (!val_s2.empty()) || carry ){
			int temp = carry;
			temp += (val_s1.empty()) ? 0 : val_s1.top();
			temp += (val_s2.empty()) ? 0 : val_s2.top();

			ListNode* new_node = new ListNode(temp%10);
			if(output){
				new_node->next = output;
				output = new_node;
			}
			else output = new_node;

			carry = temp/10;
			if(!val_s1.empty()) val_s1.pop();
			if(!val_s2.empty()) val_s2.pop();
		}

		return output;
    }
};
