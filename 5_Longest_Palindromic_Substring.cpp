/*Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"*/
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		//expand from center
		int l, r;
		int p_l = 0, p_r = 0;

		for(int i=0; i<(int)s.size(); ++i){
			//scenario 1
			//expand from s[i]
			//scenario 2
			//expand from s[i] and s[i+1]
			for(int j=i; j<=(i+1); ++j){
				l = i;
				r = j;
				while( (l>=0)&&(r<(int)s.size())&& \
						(s[l]==s[r]) ){
					if((r-l)>(p_r-p_l)){
						p_r = r;
						p_l = l;
					}
					l--;
					r++;
				}
			}
		}

		return s.substr(p_l, p_r-p_l+1);
    }
};
