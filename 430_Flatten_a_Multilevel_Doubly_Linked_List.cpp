/*
You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

 

Example:

Input:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

Output:
1-2-3-7-8-11-12-9-10-4-5-6-NULL
*/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
#define NULL 0
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
private:
	Node* flattenAndGetTail(Node* head){
		if(NULL==head) return NULL;
		Node* tail = head;
		while( (tail->child==NULL)&&(tail->next) ){
			tail = tail->next;
		}

		if(NULL!=tail->child){
			Node* temp1 = tail->next;
			tail->next = tail->child;
			tail->child->prev = tail;
			tail->child = NULL;
			Node* temp2 = flattenAndGetTail(tail->next);
			temp2->next = temp1;
			if(temp1){
				temp1->prev = temp2;
				return flattenAndGetTail(temp1);
			}
			else return temp2;
		}
		return tail;
	}
public:
    Node* flatten(Node* head) {
		flattenAndGetTail(head);
		return head;
    }
};
