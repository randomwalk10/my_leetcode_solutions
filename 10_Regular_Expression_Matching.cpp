/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
		bool* dp = new bool[(s.size()+1)*(p.size()+1)];

		for(size_t j=0; j<=p.size(); ++j){
			for(size_t i=0; i<=s.size(); ++i){
				size_t new_i = s.size() - i;
				size_t new_j = p.size() - j;
				bool first_match = (new_i<s.size()) && (new_j<p.size()) && \
								   ( (s[new_i]==p[new_j]) || ('.'==p[new_j]) );
				if( (new_i==s.size())&&(new_j==p.size()) )
					dp[(p.size()+1)*new_i+new_j] = true;
				else if(new_j==p.size())
					dp[(p.size()+1)*new_i+new_j] = false;
				else if( (new_j<(p.size()-1))&&(p[new_j+1]=='*') ){
					dp[(p.size()+1)*new_i+new_j] = dp[(p.size()+1)*new_i+(new_j+2)] || \
												   (first_match && dp[(p.size()+1)*(new_i+1)+new_j]);
				}
				else dp[(p.size()+1)*new_i+new_j] = first_match && dp[(p.size()+1)*(new_i+1)+(new_j+1)]; 
			}
		}
		bool result = dp[0];
		delete[] dp;

		return result;
    }
};
