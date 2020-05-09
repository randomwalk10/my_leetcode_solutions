/*
Given a string s, return the maximum number of ocurrences of any substring under the following rules:

The number of unique characters in the substring must be less than or equal to maxLetters.
The substring size must be between minSize and maxSize inclusive.
 

Example 1:

Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 ocurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
Example 2:

Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
Example 3:

Input: s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
Output: 3
Example 4:

Input: s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
Output: 0
 

Constraints:

1 <= s.length <= 10^5
1 <= maxLetters <= 26
1 <= minSize <= maxSize <= min(26, s.length)
s only contains lowercase English letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-occurrences-of-a-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(minSize*s.size()). The trick is that the max occurences of substrings with minSize
 * is alreay greater or equal to that of substrings with length>minSize */

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
		int res = 0;
		int count[26] = {0};
		int unique_letters = 0;
		unordered_map<string, int> freqs;

		for(int i=0; i<=(int)s.size()-minSize; ++i){
			if(i==0){
				int j;
				for (j = 0; j < minSize; ++j) {
					if(count[s[j]-'a']) ;
					else unique_letters+=1;
					count[s[j]-'a'] += 1;
				}
			}
			else{
				// reduce
				count[s[i-1]-'a'] -= 1;
				if(count[s[i-1]-'a']>0) ;
				else{
					unique_letters -= 1;
				}
				// add
				if(count[s[i+minSize-1]-'a']>0) ;
				else{
					unique_letters += 1;
				}
				count[s[i+minSize-1]-'a'] += 1;
			}
			if(unique_letters<=maxLetters){
				string temp(s.begin()+i, s.begin()+i+minSize);
				freqs[temp] += 1;
				res = max(res, freqs[temp]);
			}
		}

		return res;
    }
};
