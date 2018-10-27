/*
Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].
*/
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
private:
	bool isSubSeq(vector<multiset<int>>& lut_list, string& word){
		int j=0;
		for(int i=0; i<(int)word.length(); ++i){
			multiset<int>::iterator iter = lut_list[word[i]-'a'].lower_bound(j);
			if(lut_list[word[i]-'a'].end()==iter) return false;
			j = *iter + 1;
		}
		return true;
	}
public:
    int numMatchingSubseq(string S, vector<string>& words) {
		int cnt=0;
		vector<multiset<int>> lut_list(26, multiset<int>());

		for(int i=0; i<(int)S.length(); ++i){
			lut_list[S[i]-'a'].insert(i);
		}

		for(int i=0; i<(int)words.size(); ++i){
			if(isSubSeq(lut_list, words[i])) cnt++;
		}

		return cnt;
    }
};
