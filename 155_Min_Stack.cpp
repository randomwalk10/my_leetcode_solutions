/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(1) in time and O(n) in space */

#include <stdlib.h>

struct StackNode{
    int val;
    StackNode* next;
    StackNode* prev;
    StackNode(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};

class MinStack {
private:
    StackNode* cur_node;
    StackNode* min_node;
public:
    /** initialize your data structure here. */
    MinStack() {
        cur_node = NULL;
        min_node = NULL;
    }

    ~MinStack(){
        if(cur_node) delete cur_node;
        if(min_node) delete min_node;
    };

    void push(int x) {
        if(cur_node){
            cur_node->next = new StackNode(x);
            cur_node->next->prev = cur_node;
            cur_node = cur_node->next;
            min_node->next = new StackNode(min(x, min_node->val));
            min_node->next->prev = min_node;
            min_node = min_node->next;
        }
        else{
            cur_node = new StackNode(x);
            min_node = new StackNode(x);
        }
    }

    void pop() {
        if(cur_node){
            if(cur_node->prev){
                cur_node = cur_node->prev;
                delete cur_node->next;
                cur_node->next = NULL;
                min_node = min_node->prev;
                delete min_node->next;
                min_node->next = NULL;
            }
            else{
                delete cur_node; cur_node = NULL;
                delete min_node; min_node = NULL;
            }
        }
    }

    int top() {
        return cur_node->val;
    }

    int getMin() {
        return min_node->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
