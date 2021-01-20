/*
You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.

 

Example 1:

Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
Example 2:

Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.
 

Constraints:

1 <= s.length <= 105
s[i] is 'a' or 'b'​​.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-deletions-to-make-string-balanced
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int cnt_a = 0, cnt_b = 0;
        int res = 0;
        for(auto c:s){
            if(c=='a') ++cnt_a;
        }
        for(auto c:s){
            if(c=='a'){
                if(cnt_b>0){
                    if(cnt_b>=cnt_a){
                        res += cnt_a;
                        break;
                    }
                    else if(cnt_b<cnt_a){
                        --cnt_b;
                        ++res;
                    }
                }
                --cnt_a;
            }
            else ++cnt_b;
        }
        return res;
    }
};