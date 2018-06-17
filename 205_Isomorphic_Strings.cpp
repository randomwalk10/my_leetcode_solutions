/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while
preserving the order of characters. No two characters may map to the same
character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
*/
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		if(s.size()!=t.size()) return false;
		unordered_map<char, char> mapping;
		unordered_set<char> values;
		for(size_t i=0; i<s.size(); ++i){
			if(mapping.find(s[i])!=mapping.end()){
				if(mapping[s[i]] != t[i]) return false;
			}
			else if(values.find(t[i])!=values.end()) return false;
			else{
				mapping[s[i]] = t[i];
				values.insert(t[i]);
			}
		}
		return true;
    }
};
