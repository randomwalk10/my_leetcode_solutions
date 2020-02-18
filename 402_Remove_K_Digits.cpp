/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-k-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(N) in time and O(N) in space */
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if((int)num.size()==k) return "0";

        string res;
        stack<char> s;
        int cnt = 0;
        for(int i=0; i<(int)num.size(); ++i){
            while( (!s.empty())&&(s.top()>num[i])&&(cnt<k) ){
                s.pop();
                ++cnt;
            }
            s.push(num[i]);
        }

        stack<char> l;
        cnt = 0;
        while(!s.empty()){
            l.push(s.top()); s.pop();
        }
        while(cnt<(int)num.size()-k){
            ++cnt;
            char digit = l.top(); l.pop();
            if( (digit=='0')&&res.empty() ){
                continue;
            }
            res.push_back(digit);
        }

        if(res.empty()) res = "0";
        return res;
    }
};
