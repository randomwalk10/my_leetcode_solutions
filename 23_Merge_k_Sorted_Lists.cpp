/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
	ListNode* mergetTwoLists(ListNode* l1, ListNode* l2){
		ListNode* result = NULL;
		ListNode* tail = NULL;
		while( (l1!=NULL)||(l2!=NULL) ){
			//find the next node
			ListNode* temp;
			if(l1==NULL){
				temp = l2;
				l2 = l2->next;
			}
			else if(l2==NULL){
				temp = l1;
				l1 = l1->next;
			}
			else if(l1->val < l2->val){
				temp = l1;
				l1 = l1->next;
			}
			else{
				temp = l2;
				l2 = l2->next;
			}
			//link nodes	
			if(result){
				tail->next = temp;
				tail = tail->next;
			}
			else{
				result = temp;
				tail = temp;
			}
		}
		return result;
	}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.size()==0) return NULL;
		vector<ListNode*> cur_lists	= lists;
		while(cur_lists.size()>1){
			vector<ListNode*> next_lists;
			for(size_t i=0; i<cur_lists.size()/2; ++i){
				ListNode* new_node = mergetTwoLists(cur_lists[2*i], cur_lists[2*i+1]);
				next_lists.push_back(new_node);
			}
			if(cur_lists.size()%2) next_lists.push_back(cur_lists.back());
			cur_lists = next_lists;
		}
		return cur_lists[0];
    }
};
