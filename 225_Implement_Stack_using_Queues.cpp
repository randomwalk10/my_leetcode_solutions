/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
Notes:

You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-stack-using-queues
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> a, b;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if(a.empty()) b.push(x);
        else a.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        if(a.empty()){
            while(!b.empty()){
                res = b.front(); b.pop();
                if(!b.empty()) a.push(res);
            }
        }
        else{
            while(!a.empty()){
                res = a.front(); a.pop();
                if(!a.empty()) b.push(res);
            }
        }
        return res;
    }

    /** Get the top element. */
    int top() {
        int res;
        if(a.empty()){
            while(!b.empty()){
                res = b.front(); b.pop();
                a.push(res);
            }
        }
        else{
            while(!a.empty()){
                res = a.front(); a.pop();
                b.push(res);
            }
        }
        return res;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return a.empty()&&b.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
