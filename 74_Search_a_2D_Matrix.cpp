/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if(matrix.empty()) return false;
		else if(matrix[0].empty()) return false;
		int t = 0, b = matrix.size()-1, l = 0, r = matrix[0].size()-1;

		//search for row
		while(b>t){
			if( (target<matrix[t][0]) || (target>matrix[b][matrix[0].size()-1]) ) return false;
			int mid = (t+b)/2;
			if(target<matrix[mid][0]) b = mid - 1;
			else if(target>matrix[mid][matrix[0].size()-1]) t = mid + 1;
			else{
				b = mid;
				break;
			}
		}
		//search for column
		while(r>l){
			if( (target<matrix[b][l]) || (target>matrix[b][r]) ) return false;
			int mid = (l+r)/2;
			if( target<matrix[b][mid] ) r = mid - 1;
			else if( target>matrix[b][mid] ) l = mid + 1;
			else return true;
		}

		return matrix[b][r] == target;
    }
};
