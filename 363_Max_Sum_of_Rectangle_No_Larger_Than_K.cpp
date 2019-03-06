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
#include <set>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		int res = INT_MIN;
		int m = max(rows, cols); // longer dimension
		int n = min(rows, cols); // shorter dimension
		bool isRowLonger = (rows>cols);

		for(int i=0; i<n; ++i){ // start from i
			vector<int> sums(m, 0); // a vector of sums for longer dimension
			for(int j=i; j<n; ++j){ // end at j
				// update sums
				for(int p=0; p<m; ++p){
					if(isRowLonger) sums[p] += matrix[p][j];
					else sums[p] += matrix[j][p];
				}

				// find the max sum of subarrays of sums that is not larger than k
				set<int> accur_sums = {0}; // add zero for cases where the subarray start at index 0
				int cur_sums = 0;
				for(int sum : sums){
					// update cur_sums
					cur_sums += sum;

					// find an element past_sums in accur_sums that maximizes cur_sums - past_sums
					// while making sure cur_sums - past_sums <= k 
					set<int>::iterator iter = accur_sums.lower_bound(cur_sums - k);
					if(iter!=accur_sums.end()) res = max(res, cur_sums - *iter);

					// update accur_sums
					accur_sums.insert(cur_sums);
				}
			}
		}

		return res;
    }
};
