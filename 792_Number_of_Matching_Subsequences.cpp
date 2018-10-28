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

using namespace std;
vector<vector<int>> lut_list(50000, vector<int>(26, -1));

class Solution {
private:
	bool isSubSeq(string& word, int max_len){
		int j=0;
		for(int i=0; i<(int)word.length(); ++i){
			if(j>=max_len) return false;
			j = lut_list[j][word[i]-'a'];
			if(j<0) return false;
			j++;
		}
		return true;
	}
public:
    int numMatchingSubseq(string S, vector<string>& words) {
		int cnt=0;

		for(int i=0; i<(int)S.length(); ++i){
			int idx = (int)S.length()-1-i;
			if(i!=0) lut_list[idx] = lut_list[idx+1];
			else lut_list[idx] = vector<int>(26, -1);
			lut_list[idx][S[idx]-'a'] = idx;
		}

		for(int i=0; i<(int)words.size(); ++i){
			if(isSubSeq(words[i], (int)S.length())) cnt++;
		}

		return cnt;
    }
};
