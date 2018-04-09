/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int max_cnt = 0;
		vector<int> dict(256, -1);
		int start = -1;
		for(int i = 0; i< (int)s.length(); ++i){
			if(dict[s[i]]>start){
				start = dict[s[i]];
			}
			dict[s[i]] = i;
			max_cnt = ((i-start)>max_cnt) ? (i-start) : max_cnt;
		}
		return max_cnt;
    }
};
