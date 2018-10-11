/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
Example 1:

Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
		if(s1.length()>s2.length()) return false;
		vector<int> s1_f(26, 0);
		vector<int> s2_f(26, 0);

		//fill s1_f
		for(size_t i=0; i<s1.length(); ++i){
			s1_f[s1[i]-'a'] += 1;
			s2_f[s2[i]-'a'] += 1;
		}

		int l = 0;
		int r = l+s1.length();
		do{
			if(s1_f==s2_f) return true;

			if(r>=(int)s2.length()) break;
			s2_f[s2[l++]-'a'] -= 1;
			s2_f[s2[r++]-'a'] += 1;
		}while(true);

		return false;
    }
};
