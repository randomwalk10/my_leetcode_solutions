/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
		vector<int> out;
		if(p.empty()) return out;
		if(s.size()<p.size()) return out;
		vector<int> p_count(26, 0);
		vector<int> s_count(26, 0);

		for(size_t i=0; i<p.size(); i++){
			p_count[p[i]-'a'] += 1;
			s_count[s[i]-'a'] += 1;
		}

		size_t start = 0;
		do{
			//compare(vector<int> comparison is much faster than array comparison)
			if(p_count==s_count) out.push_back(start);

			//update
			if(start+p.size()<s.size()){
				s_count[s[start]-'a'] -= 1;
				s_count[s[start+p.size()]-'a'] += 1;
				start++;
			}
			else break;
		}while(1);

		return out;
    }
};
