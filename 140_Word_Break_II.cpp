/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/*need to improve timing performance, currently beating only 30% on leetcode: (*/
class Solution {
private:
	bool startWith(string s, string t){
		if(s.size()<t.size()) return false;
		for(size_t i=0; i<t.size(); ++i){
			if(s[i]!=t[i]) return false;
		}
		return true;
	}
	vector<string> wordBreak(string s, vector<string>& wordDict, \
			unordered_map<string, vector<string>>& word_breaks){
		if(word_breaks.count(s)) return word_breaks[s]; 
		vector<string> out;
		for(size_t i=0; i<wordDict.size(); ++i){
			if(startWith(s, wordDict[i])){
				string temp_s = s;
				temp_s.erase(0, wordDict[i].size());
				//is s==wordDict[i]
				//if not, branch out
				if(temp_s.empty())
					out.push_back(wordDict[i]);
				else{
					vector<string> temp_o;
					temp_o = wordBreak(temp_s, wordDict, word_breaks);
					if(false==temp_o.empty()){
						for(size_t j=0; j<temp_o.size(); ++j){
							out.push_back(wordDict[i]+" "+temp_o[j]);
						}
					}
				}
			}
		}
		word_breaks[s] = out;
		return out;
	}
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_map<string, vector<string>> word_breaks;
		return wordBreak(s, wordDict, word_breaks);
    }
};
