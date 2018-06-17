/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string getHashCode(string a){
		int table[26] = {0};
		string out;
		for(size_t i=0; i<a.size(); ++i)
			table[a[i]-'a']++;
		for(int i=0; i<26; ++i){
			while(table[i]--) out.push_back('a'+i);
		}
		return out;
	}

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> dict;
		vector<vector<string>> out;
		for(size_t i=0; i<strs.size(); ++i){
			string hash_code = this->getHashCode(strs[i]);
			if(dict.find(hash_code)!=dict.end())
				dict[hash_code].push_back(strs[i]);
			else{
				vector<string> temp = {strs[i]};
				dict[hash_code] = temp;
			}
		}
		for(unordered_map<string, vector<string>>::iterator iter = \
				dict.begin(); iter != dict.end(); ++iter)
			out.push_back(iter->second);
		return out;
    }
};
