/*
Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can break some permutation of string s2 or vice-versa. In other words s2 can break s1 or vice-versa.

A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.

 

Example 1:

Input: s1 = "abc", s2 = "xya"
Output: true
Explanation: "ayx" is a permutation of s2="xya" which can break to string "abc" which is a permutation of s1="abc".
Example 2:

Input: s1 = "abe", s2 = "acd"
Output: false 
Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", "eab" and "eba" and all permutation for s2="acd" are: "acd", "adc", "cad", "cda", "dac" and "dca". However, there is not any permutation from s1 which can break some permutation from s2 and vice-versa.
Example 3:

Input: s1 = "leetcodee", s2 = "interview"
Output: true
 

Constraints:

s1.length == n
s2.length == n
1 <= n <= 10^5
All strings consist of lowercase English letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-a-string-can-break-another-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
		vector<int> a1(26, 0);
		vector<int> a2(26, 0);
		for (size_t i = 0; i < s1.size(); ++i) {
			a1[s1[i]-'a'] += 1;
		}
		for (size_t i = 0; i < s2.size(); ++i) {
			a2[s2[i]-'a'] += 1;
		}
		int cnt = 0;
		for (size_t i = 0; i < 26; ++i) {
			cnt += a1[i];
			if(a2[i]>=cnt) cnt = 0;
			else cnt -= a2[i];
		}
		if(cnt==0) return true;
		cnt = 0;
		for (size_t i = 0; i < 26; ++i) {
			cnt += a2[i];
			if(a1[i]>=cnt) cnt = 0;
			else cnt -= a1[i];
		}
		return cnt==0;
    }
};
