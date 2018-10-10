/*
You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern. 

You may return the answer in any order.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
 

Note:

1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20
*/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
	bool isPatternMatched(string& word, string& pattern){
		if(word.length()!=pattern.length()) return false;

		// hash table method
		/*
		unordered_map<char, char> w2p;
		unordered_map<char, char> p2w;

		for(size_t i=0; i<word.length(); ++i){
			if( (w2p.end()==w2p.find(word[i])) && (p2w.end()==p2w.find(pattern[i])) ){
				w2p[word[i]] = pattern[i];
				p2w[pattern[i]] = word[i];
			}
			else if( (w2p.end()!=w2p.find(word[i])) && (p2w.end()!=p2w.find(pattern[i])) ){
				if( (w2p[word[i]]!=pattern[i]) || (p2w[pattern[i]]!=word[i]) )
					return false;
			}
			else
				return false;
		}
		*/

		// array method
		vector<int> w2p(128, 0);
		vector<int> p2w(128, 0);
		for(size_t i=0; i<word.length(); ++i){
			if( (w2p[word[i]]==0) && (p2w[pattern[i]]==0) ){
				w2p[word[i]] = pattern[i];
				p2w[pattern[i]] = word[i];
			}
			else if( (w2p[word[i]]==0) || (p2w[pattern[i]]==0) || \
					(w2p[word[i]]!=pattern[i]) || (p2w[pattern[i]]!=word[i]) )
				return false;
		}

		return true;
	}
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> out;

		for(size_t i=0; i<words.size(); ++i){
			if(this->isPatternMatched(words[i], pattern))
				out.push_back(words[i]);
		}

		return out;
    }
};
