/*
You are given a string s, a split is called good if you can split s into 2 non-empty strings p and q where its concatenation is equal to s and the number of distinct letters in p and q are the same.

Return the number of good splits you can make in s.

 

Example 1:

Input: s = "aacaba"
Output: 2
Explanation: There are 5 ways to split "aacaba" and 2 of them are good. 
("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.
Example 2:

Input: s = "abcd"
Output: 1
Explanation: Split the string as follows ("ab", "cd").
Example 3:

Input: s = "aaaaa"
Output: 4
Explanation: All possible splits are good.
Example 4:

Input: s = "acbadbaada"
Output: 2
 

Constraints:

s contains only lowercase English letters.
1 <= s.length <= 10^5


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-good-ways-to-split-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numSplits(string s) {
		vector<int> l_char(26, 0);
		vector<int> r_char(26, 0);
		vector<int> r_cnt(s.size(), 0);
		int res = 0;

		int tmp = 0;
		for (int i = s.size()-1; i >= 0; --i) {
			if(r_char[s[i]-'a']==0){
				r_char[s[i]-'a'] = 1;
				++tmp;
			}
			r_cnt[i] = tmp;
		}

		tmp = 0;
		for (int i = 0; i < s.size()-1; ++i) {
			if(l_char[s[i]-'a']==0){
				l_char[s[i]-'a'] = 1;
				++tmp;
			}
			if(tmp==r_cnt[i+1]) ++res;
		}

		return res;
    }
};
