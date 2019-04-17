/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
		int len = s.size();
		if(len<=1) return len;
		// construct a matrix dp where dp[i][j] represents the max length of palindromic subsequences in [i, j] of s
		vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

		// perform dynamic programming to find dp[i][j] for any i<=j
		for(int r=0; r<len; ++r){
			dp[r][r] = 1;
			for(int l=r-1; l>=0; --l){
				if(s[r]==s[l]){
					if(r==l+1)
						dp[l][r] = 2;
					else
						dp[l][r] = max(2+dp[l+1][r-1], dp[l][r]);
				}
				dp[l][r] = max(dp[l+1][r], dp[l][r]);
				dp[l][r] = max(dp[l][r-1], dp[l][r]);
			}
		}

		// return
		return dp[0][len-1];
    }
};
