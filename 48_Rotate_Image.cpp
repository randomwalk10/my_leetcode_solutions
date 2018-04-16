/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		int N = (int)matrix.size();
		if(N<=1) return;

		for(int j=0; j<=(N-1)/2; ++j){
			if( (N%2)&&(j==(N-1)/2) ) continue;
			for(int i=0; i<=(N-1)/2; ++i){
				int prev_i = i;
				int prev_j = j;
				int new_i = N-1-j;
				int new_j = i;
				int prev_temp = matrix[prev_j][prev_i];
				for(int w=0; w<4; ++w){
					int temp = matrix[new_j][new_i];
					matrix[new_j][new_i] = prev_temp;
					prev_temp = temp;
					prev_i = new_i;
					prev_j = new_j;
					new_i = N-1-prev_j;
					new_j = prev_i;
				}
			}
		}

		return;
    }
};
