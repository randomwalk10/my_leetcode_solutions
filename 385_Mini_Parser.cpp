/*
Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
Example 1:

Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
Example 2:

Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/mini-parser
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/* O(N) in time and O(N) in space */
#include <stack>
#include <string>
using namespace std;

class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger *head = NULL, *tail;
        stack<NestedInteger*> l;
        int i=0;
        int cur=0;
        bool sign=true;
        bool num_available=false;
        while(i<(int)s.size()){
            if( (s[i]>='0')&&(s[i]<='9') ){
                cur = cur*10 + s[i] - '0';
                num_available = true;
            }
            else if(s[i]=='['){
                if(head){
                    l.push(tail);
                    tail = new NestedInteger();
                }
                else{
                    head = new NestedInteger();
                    tail = head;
                }
            }
            else if( (s[i]==']')||(s[i]==',') ){ // ']' or ','
                if(num_available){
                    cur = (sign)?cur:(-cur);
                    tail->add(NestedInteger(cur));
                    cur = 0;
                    num_available = false;
                    sign = true;
                }
                if(s[i]==']'){
                    if(l.empty()){
                        break;
                    }
                    else{
                        NestedInteger* prev = l.top(); l.pop();
                        prev->add(*tail);
                        tail = prev;
                    }
                }
            }
            else if(s[i]=='-'){
                sign = false;
            }
            // update i
            ++i;
        }
        if( (head==NULL)&&num_available ){
            cur = (sign)?cur:(-cur);
            head = new NestedInteger(cur);
        }
        return *head;
    }
};
