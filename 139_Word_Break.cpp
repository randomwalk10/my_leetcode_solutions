/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
		int *p = new int[s.length()+1];
		for(int i=0; i<=(int)s.length(); ++i) p[i] = 0;
		p[0] = 1;
		for(int i=1; i<=(int)s.length(); ++i){
			for(vector<string>::iterator iter = wordDict.begin(); \
					iter != wordDict.end(); ++iter){
				int j = i - iter->size();
				if( (0<=j) && p[j] && (s.substr(j, iter->size())==*iter) ){
					p[i] = 1;
					break;
				}
			}
		}
		bool result = p[s.length()];
		delete[] p;
		return result;
    }
};
