/*
We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.

 

Example 1:

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
*/

#include <vector>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
		int res = 0;
		int rows = A.size(), cols = A[0].size();
		int row_flips = 0;

		// iterate through each column
		for(int c=0; c<cols; ++c){
			int tmp = 0;
			// iterate through each row
			for(int r=0; r<rows; ++r){
				if(0==c){
					if(A[r][c]==0) row_flips |= 1<<r;
					++tmp;
				}
				else{
					tmp += A[r][c]^((row_flips&(1<<r))>>r);
				}
			}
			// flip tmp if tmp <= rows / 2
			// this is column flip
			if(tmp<=(rows>>1)) tmp = rows - tmp;
			// update res
			res = (res<<1) + tmp;
		}

		// return
		return res;
    }
};
