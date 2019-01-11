/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:

The input string length won't exceed 1000.
*/
#include <string>
using namespace std;

class Solution {
private:
	int countOdd(string& s, int i, int len){
		int l = i, r = i;
		int cnt = 0;
		while( (l>=0)&&(r<len) ){
			if(s[l]==s[r]){
				cnt++;
				l--;
				r++;
			}
			else break;
		}
		return cnt;
	}
	int countEven(string& s, int i, int len){
		int l = i, r = i+1;
		int cnt = 0;
		while( (l>=0)&&(r<len) ){
			if(s[l]==s[r]){
				cnt++;
				l--;
				r++;
			}
			else break;
		}
		return cnt;
	}
public:
    int countSubstrings(string s) {
		int n = s.size();
		int res = 0;
		for(int i=0; i<n; ++i){
			res += countOdd(s, i, n);
			res += countEven(s, i, n);
		}
		return res;
    }
};
