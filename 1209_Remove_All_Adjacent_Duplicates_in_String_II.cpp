/*
Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.

 

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
 

Constraints:

1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(N) in time and O(N) in space */
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> a;
        stack<int> b;
        string res;

        for(int i=0; i<(int)s.size(); ++i){
            if( (!a.empty())&&(a.top()==s[i]) ){
                if(b.top()==k-1){
                    a.pop();
                    b.pop();
                }
                else{
                    int temp = b.top(); b.pop();
                    b.push(temp+1);
                }
            }
            else{
                a.push(s[i]);
                b.push(1);
            }
        }

        stack<char> a_r;
        stack<int> b_r;
        while(!a.empty()){
            a_r.push(a.top());
            b_r.push(b.top());
            a.pop();
            b.pop();
        }
        while(!a_r.empty()){
            for(int i=0; i<b_r.top(); ++i){
                res.push_back(a_r.top());
            }
            a_r.pop();
            b_r.pop();
        }

        return res;
    }
};
