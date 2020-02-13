/*
Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
Example 4:

Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"
 

Constraints:

1 <= s.length <= 10^5
s[i] is one of  '(' , ')' and lowercase English letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-remove-to-make-valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/* O(n) in time and O(n) in space */
#include <stack>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> c;
        stack<int> e;
        queue<int> d;
        string res;

        for(int i=0; i<(int)s.size(); ++i){
            if(s[i]=='('){
                c.push(i);
            }
            else if(s[i]==')'){
                if(c.empty()){
                    d.push(i);
                }
                else{
                    c.pop();
                }
            }
        }
        while(!c.empty()){
            e.push(c.top());
            c.pop();
        }
        while(!e.empty()){
            d.push(e.top());
            e.pop();
        }
        for(int i=0; i<(int)s.size(); ++i){
            if(i==d.front()){
                d.pop();
            }
            else res.push_back(s[i]);
        }

        return res;
    }
};
