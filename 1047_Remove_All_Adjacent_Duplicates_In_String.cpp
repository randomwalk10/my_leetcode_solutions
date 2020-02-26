/*
Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

 

Example 1:

Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
 

Note:

1 <= S.length <= 20000
S consists only of English lowercase letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(N) in time and O(N) in time */
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        string res;

        for(int i=0; i<(int)S.size(); ++i){
            if( (!s.empty())&&(s.top()==S[i]) ){
                s.pop();
            }
            else{
                s.push(S[i]);
            }
        }

        stack<char> l;
        while(!s.empty()){
            l.push(s.top()); s.pop();
        }
        while(!l.empty()){
            res.push_back(l.top()); l.pop();
        }

        return res;
    }
};
