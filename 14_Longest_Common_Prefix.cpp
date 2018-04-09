/*
Write a function to find the longest common prefix string amongst an array of strings.
For example:
{“a”,“a”,“b”} should give “” as there is nothing common in all the 3 strings.
{“a”, “a”} should give “a” as a is longest common prefix in all the strings.
{“abca”, “abc”} as abc
{“ac”, “ac”, “a”, “a”} as a.
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		if(strs.empty()) return "";
		string result = strs[0];
		for(size_t i=1; i< strs.size(); ++i){
			size_t min_len = (result.size() > strs[i].size()) ? \
							 strs[i].size() : result.size();
			size_t j = 0;
			for(; j<min_len; ++j){
				if(result[j]!=strs[i][j]) break;
			}
			if(j==0) return "";
			result.resize(j);
		}
		return result;
    }
};
