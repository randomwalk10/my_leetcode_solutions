/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
*/
#include <algorithm>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
		if((m<=0)||(n<=0)) return 0;
		else if((m==1)||(n==1)) return 1;

		long long output = 1;
		int j = 1;
		m--;
		n--;
		if(m<n) swap(m, n);

		for(int i=m+1; i<=n+m; ++i, ++j){
			output *= i;
			output /= j;
		}

		return (int)output;
    }
};
