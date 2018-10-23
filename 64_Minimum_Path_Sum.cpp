/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
		vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
		dp[0][0] = grid[0][0];

		for(int r=0; r<(int)grid.size(); ++r){
			for(int c=0; c<(int)grid[0].size(); ++c){
				if(r>0) dp[r][c] = grid[r][c] + dp[r-1][c];
				if(c>0){
					if(dp[r][c]!=0)
						dp[r][c] = (grid[r][c]+dp[r][c-1]<dp[r][c]) ? \
								   grid[r][c]+dp[r][c-1] : dp[r][c];
					else
						dp[r][c] = grid[r][c]+dp[r][c-1];
				}
			}
		}

		return dp[(int)grid.size()-1][(int)grid[0].size()-1];
    }
};
