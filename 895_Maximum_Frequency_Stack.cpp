/*
Implement FreqStack, a class which simulates the operation of a stack-like data structure.

FreqStack has two functions:

push(int x), which pushes an integer x onto the stack.
pop(), which removes and returns the most frequent element in the stack.
If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.
 

Example 1:

Input: 
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
Output: [null,null,null,null,null,null,null,5,7,5,4]
Explanation:
After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

pop() -> returns 5, as 5 is the most frequent.
The stack becomes [5,7,5,7,4].

pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
The stack becomes [5,7,5,4].

pop() -> returns 5.
The stack becomes [5,7,4].

pop() -> returns 4.
The stack becomes [5,7].
 

Note:

Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.
It is guaranteed that FreqStack.pop() won't be called if the stack has zero elements.
The total number of FreqStack.push calls will not exceed 10000 in a single test case.
The total number of FreqStack.pop calls will not exceed 10000 in a single test case.
The total number of FreqStack.push and FreqStack.pop calls will not exceed 150000 across all test cases.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-frequency-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(N) in time and O(N) in space */
#include <vector>
#include <unordered_map>
using namespace std;

class FreqStack {
private:
    vector<stack<int>> order;
    unordered_map<int, int> freq;
    int max_cnt;
public:
    FreqStack() {
        max_cnt = 0;
    }

    void push(int x) {
        int cnt;
        freq[x] += 1;
        cnt = freq[x];
        if(cnt>(int)order.size()){
            stack<int> temp;
            temp.push(x);
            order.push_back(temp);
            max_cnt = cnt;
        }
        else if(cnt>max_cnt){
            order[cnt-1].push(x);
            max_cnt = cnt;
        }
        else{
            order[cnt-1].push(x);
        }
    }

    int pop() {
        int res = order[max_cnt-1].top();
        order[max_cnt-1].pop();
        freq[res] -= 1;
        if(order[max_cnt-1].empty()){
            max_cnt -= 1;
        }
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
