/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		if(matrix.empty()||matrix[0].empty()) return;

		vector<bool> col_zeros(matrix.size(), false);
		vector<bool> row_zeros(matrix[0].size(), false);

		for(int x=0; x<(int)matrix.size(); ++x){
			for(int y=0; y<(int)matrix[0].size(); ++y){
				if(matrix[x][y]==0){
					col_zeros[x] = true;
					row_zeros[y] = true;
				}
			}
		}

		for(int x=0; x<(int)matrix.size(); ++x){
			if(col_zeros[x]){
				for(int y=0; y<(int)matrix[0].size(); ++y){
					matrix[x][y] = 0;
				}
			}
		}

		for(int y=0; y<(int)matrix[0].size(); ++y){
			if(row_zeros[y]){
				for(int x=0; x<(int)matrix.size(); ++x){
					matrix[x][y] = 0;
				}
			}
		}

		return;
    }
};
