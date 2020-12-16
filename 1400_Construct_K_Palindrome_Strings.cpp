/*
Given a string s and an integer k. You should construct k non-empty palindrome strings using all the characters in s.

Return True if you can use all the characters in s to construct k palindrome strings or False otherwise.

 

Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.
Example 3:

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.
Example 4:

Input: s = "yzyzyzyzyzyzyzy", k = 2
Output: true
Explanation: Simply you can put all z's in one string and all y's in the other string. Both strings will be palindrome.
Example 5:

Input: s = "cr", k = 7
Output: false
Explanation: We don't have enough characters in s to construct 7 palindromes.
 

Constraints:

1 <= s.length <= 10^5
All characters in s are lower-case English letters.
1 <= k <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-k-palindrome-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
		int odds = 0;
		int evens = 0;
		bool res = false;
		vector<int> cnts(26, 0);

		for (size_t i = 0; i < s.size(); ++i) {
			cnts[s[i]-'a'] += 1;
		}

		for (int i = 0; i < 26; ++i) {
			odds += cnts[i] % 2;
			evens += cnts[i] / 2;
		}

		if(odds>k) res = false;
		else if(odds==k) res = true;
		else if(odds+2*evens>=k) res = true;
		else res = false;

		return res;
    }
};
