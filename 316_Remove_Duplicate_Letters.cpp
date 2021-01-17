/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0);
        vector<bool> exists(26, false);
        string res;

        for(auto t:s){
            ++cnt[t-'a'];
        }

        for(auto t:s){
            if(exists[t-'a']==false){
                while((res.empty()==false)&&(res.back()>t)&&(cnt[res.back()-'a']>0)){
                    exists[res.back()-'a'] = false;
                    res.pop_back();
                }
                res.push_back(t);
                exists[t-'a'] = true;
            }
            --cnt[t-'a'];
        }

        return res;
    }
};