/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

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
    bool isPalindrome(ListNode* head) {
		if(NULL==head) return true;
		stack<int> val_s;
		ListNode* temp = head;
		while(temp){
			val_s.push(temp->val);
			temp = temp->next;
		}

		temp = head;
		while(temp){
			if(temp->val != val_s.top()) return false;
			val_s.pop();
			temp = temp->next;
		}

		return true;
    }
};
