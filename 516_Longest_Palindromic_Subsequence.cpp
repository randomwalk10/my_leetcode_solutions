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
		// construct a vector dp where dp[i] is the maximal length of subsequences in s[i:]
		vector<int> dp(len, 1);

		// perform dynamic programming to find dp[i][j] for any i<=j
		for(int r=1; r<len; ++r){
			int prev1 = 1; // maximal length of subseq in s[l+1:r+1]
			int prev2 = 0; // maxmal length of subseq in s[l+1:r]
			for(int l=r-1; l>=0; --l){
				// store the maximal length of subseq in s[l:r]
				int temp = dp[l];
				// update dp[l]
				if(s[l]==s[r]){
					dp[l] = 2 + prev2;
				}
				else{
					dp[l] = max(prev1, dp[l]);
				}
				// update prev2
				prev2 = temp;
				// update prev1
				prev1 = dp[l];
			}
		}

		// return
		return dp[0];
    }
};
