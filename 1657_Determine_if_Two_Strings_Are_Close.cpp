/*
Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 

Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
Example 4:

Input: word1 = "cabbba", word2 = "aabbss"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any amount of operations.
 

Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 contain only lowercase English letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/determine-if-two-strings-are-close
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
		if(word1.size()!=word2.size()) return false;
		vector<int> cnt1(26, 0);
		vector<int> cnt2(26, 0);
		for (int i = 0; i < word1.size(); ++i) {
			++cnt1[word1[i]-'a'];
		}
		for (int i = 0; i < word2.size(); ++i) {
			++cnt2[word2[i]-'a'];
		}
		for (int i = 0; i < 26; ++i) {
			if((cnt1[i]>0)&&(cnt2[i]==0)) return false;
			else if((cnt2[i]>0)&&(cnt1[i]==0)) return false;
		}
		sort(cnt1.begin(), cnt1.end());
		sort(cnt2.begin(), cnt2.end());
		for (int i = 25; i >= 0; --i) {
			if(cnt1[i]!=cnt2[i]) return false;
			else if(cnt1[i]==0) break;
		}
		return true;
    }
};
