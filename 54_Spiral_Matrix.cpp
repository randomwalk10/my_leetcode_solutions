/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> output;
		if( (matrix.empty()) || (matrix[0].empty()) ) return output;
		int left = 0;
		int right = matrix[0].size() - 1;
		int top = 0;
		int bottom = matrix.size() - 1;

		while((left<=right)&&(top<=bottom)){
			for(int j=left; j<(right+1); ++j)
				output.push_back(matrix[top][j]);
			for(int i=top+1; i<(bottom+1); ++i)
				output.push_back(matrix[i][right]);
			if(bottom>top)
				for(int j=right-1; j>(left-1); --j)
					output.push_back(matrix[bottom][j]);
			if(right>left)
				for(int i=bottom-1; i>top; --i)
					output.push_back(matrix[i][left]);
			left++;
			right--;
			top++;
			bottom--;
		}

		return output;
    }
};
