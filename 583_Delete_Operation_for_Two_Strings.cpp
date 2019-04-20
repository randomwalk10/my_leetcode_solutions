/*
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:

Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:

The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
		// init
		int rows = word1.size();
		int cols = word2.size();
		vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0)); // dp[r][c] is the longest length of common subsequence in word1[r:] and word2[c:]

		// search from last char to first char(reverse order)
		for(int r = rows-1; r>=0; --r){
			for(int c = cols-1; c>=0; --c){
				dp[r][c] = max(dp[r+1][c], dp[r][c+1]);
				if(word1[r]==word2[c]) dp[r][c] = max(dp[r][c], 1+dp[r+1][c+1]);
			}
		}

		// return
		return rows+cols-2*dp[0][0];
    }
};
