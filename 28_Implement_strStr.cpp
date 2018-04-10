/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		int result = -1;
		for(int i=0; i<=(int)(haystack.size()-needle.size()); ++i){
			if(haystack.substr(i, needle.size())==needle) return i;	
		}
		return result;
    }
};
