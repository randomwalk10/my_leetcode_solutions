/*
Given a string s, determine if it is valid.

A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:

Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.
Return true if s is a valid string, otherwise, return false.

 

Example 1:

Input: s = "aabcbc"
Output: true
Explanation:
"" -> "abc" -> "aabcbc"
Thus, "aabcbc" is valid.
Example 2:

Input: s = "abcabcababcc"
Output: true
Explanation:
"" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
Thus, "abcabcababcc" is valid.
Example 3:

Input: s = "abccba"
Output: false
Explanation: It is impossible to get "abccba" using the operation.
Example 4:

Input: s = "cababc"
Output: false
Explanation: It is impossible to get "cababc" using the operation.
 

Constraints:

1 <= s.length <= 2 * 104
s consists of letters 'a', 'b', and 'c'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-word-is-valid-after-substitutions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> s1;

		for (int i = 0; i < s.size(); ++i) {
			if((s[i]=='a')||(s[i]=='b')) s1.push(s[i]);
			else{
				if((s1.empty())||(s1.top()!='b')) return false;
				s1.pop();
				if((s1.empty())||(s1.top()!='a')) return false;
				s1.pop();
			}
		}

		return s1.empty();
    }
};
