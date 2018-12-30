/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();//rows
		int n = obstacleGrid[0].size();//cols
		if(obstacleGrid[m-1][n-1]) return 0;
		if(obstacleGrid[0][0]) return 0;

		vector<vector<int>> counts(m, vector<int>(n, 0));
		counts[m-1][n-1] = 1;
		for(int r = m-2; r>=0; --r)
			if(obstacleGrid[r][n-1]==0)
				counts[r][n-1] = counts[r+1][n-1];
			else break;
		for(int c = n-2; c>=0; --c)
			if(obstacleGrid[m-1][c]==0)
				counts[m-1][c] = counts[m-1][c+1];
			else break;

		for(int r = m-2; r>=0; --r){
			for(int c = n-2; c>=0; --c){
				if(obstacleGrid[r][c]==0)
					counts[r][c] = counts[r+1][c] + counts[r][c+1];
			}
		}

		return counts[0][0];
    }
};
