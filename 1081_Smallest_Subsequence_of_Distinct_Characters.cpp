/*
Return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
		string res;
		unordered_set<char> m;

		for (int i = 0; i < s.size(); ++i) {
			m.insert(s[i]);
		}

		int start = 0;
		while(!m.empty()){
			unordered_set<char> tmp;
			char obj = 0;
			int next_start;
			for (int i = s.size()-1; i >= start; --i) {
				if(m.find(s[i])!=m.end()) tmp.insert(s[i]);
				else continue;
				if(tmp.size()==m.size()){
					if((obj==0)||(s[i]<=obj)){
						obj = s[i];
						next_start = i;
					}
				}
			}
			res.push_back(obj);
			m.erase(m.find(obj));
			start = ++next_start;
		}

		return res;
	}
};
