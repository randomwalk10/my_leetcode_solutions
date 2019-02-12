/*
 Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/
#include <vector>
using namespace std;

class NumMatrix {
private:
	vector<vector<int>> sum_;

public:
    NumMatrix(vector<vector<int>> matrix) {
		if(matrix.empty()||matrix[0].empty()) return;
		sum_.resize(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
		for(int r=1; r<=(int)matrix.size(); ++r){
			for(int c=1; c<=(int)matrix[0].size(); ++c){
				sum_[r][c] = sum_[r-1][c] + sum_[r][c-1] + matrix[r-1][c-1] - \
							sum_[r-1][c-1];
			}
		}
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
		return sum_[row2+1][col2+1] - sum_[row2+1][col1] - \
			sum_[row1][col2+1] + sum_[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
