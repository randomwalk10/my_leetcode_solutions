/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
		//check the length
		if(s.length()!=t.length()) return false;
		//build counting table
		int counts[26] = {0};
		for(size_t i=0; i<s.length(); ++i){
			counts[s[i]-'a']++;
			counts[t[i]-'a']--;
		}
		//check if counting table only contains zeros
		for(size_t i=0; i<26; ++i){
			if(counts[i]) return false;
		}
		//return
		return true;
    }
};
