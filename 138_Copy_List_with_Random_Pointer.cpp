/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include <unordered_map>
using namespace std;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		unordered_map<long long, RandomListNode*> mp;

		RandomListNode *output = NULL;
		RandomListNode *temp = output;

		//create new list
		while(head){
			//add to new list
			if(output){
				temp->next = new RandomListNode(head->label);
				temp = temp->next;
			}
			else{
				temp = new RandomListNode(head->label);
				output = temp;
			}
			temp->random = head->random;
			//stort to mp
			mp[(long long)head] = temp;
			//update
			head = head->next;
		}

		//complete new list with random pointer
		temp = output;
		while(temp){
			//redirect random pointer
			if(temp->random) temp->random = \
				mp[(long long)temp->random];
			//update
			temp = temp->next;
		}

		return output;
    }
};
