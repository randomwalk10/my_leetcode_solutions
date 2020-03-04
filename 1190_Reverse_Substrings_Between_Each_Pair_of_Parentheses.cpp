/*
You are given a string s that consists of lower case English letters and brackets. 

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
Example 4:

Input: s = "a(bcdefghijkl(mno)p)q"
Output: "apmnolkjihgfedcbq"
 

Constraints:

0 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It's guaranteed that all parentheses are balanced.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(N^2) in time and O(N) in space */
#include <string>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> a;
        string res;

        for(int i=0; i<(int)s.size(); ++i){
            if(s[i]=='('){
                a.push(s[i]);
            }
            else if(s[i]==')'){
                queue<char> b;
                while(a.top()!='('){
                    b.push(a.top());
                    a.pop();
                }
                a.pop(); // remove '('

                while(!b.empty()){
                    a.push(b.front());
                    b.pop();
                }
            }
            else{
                a.push(s[i]);
            }
        }

        stack<char> b;
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
        while(!b.empty()){
            res.push_back(b.top());
            b.pop();
        }

        return res;
    }
};
