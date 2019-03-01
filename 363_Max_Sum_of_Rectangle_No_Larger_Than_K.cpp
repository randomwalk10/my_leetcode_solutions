/*
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:

Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2 
Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
             and 2 is the max number no larger than k (k = 2).
Note:

The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
*/
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		int res = INT_MIN;
		vector<vector<int>> sums(rows+1, vector<int>(cols+1, 0));

		for(int r=1; r<=rows; ++r){
			for(int c=1; c<=cols; ++c){
				// get the sum of rectangle with tl (1,1) and br (r, c)
				sums[r][c] = matrix[r-1][c-1] + sums[r-1][c] + sums[r][c-1] - \
							 sums[r-1][c-1];
				// find the maximal sum of any rectangle with br at (r, c)
				for(int ri=1; ri<=r; ++ri){
					for(int ci=1; ci<=c; ++ci){
						//update res
						int temp = sums[r][c] + sums[ri-1][ci-1] - \
								   sums[r][ci-1] - sums[ri-1][c];
						if( temp==k ) return k;
						else if( (temp<k)&&(temp>res) ) res = temp;
					}
				}
			}
		}

		return res;
    }
};
