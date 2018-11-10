/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
	vector<vector<int>> deltas = {{-1,0}, {1,0}, {0,-1}, {0,1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size(), -1));
		queue<vector<int>> q;

		//fill zeros
		for(int r=0; r<(int)matrix.size(); ++r){
			for(int c=0; c<(int)matrix[0].size(); ++c){
				if(matrix[r][c]==0){
					res[r][c] = 0;
					q.push({r, c});
				}
			}
		}

		//breadth first search
		while(!q.empty()){
			int r = q.front()[0];
			int c = q.front()[1];
			q.pop();

			for(int i=0; i<(int)deltas.size(); ++i){
				int new_r = deltas[i][0] + r;
				int new_c = deltas[i][1] + c;
				if( (new_r>=0)&&(new_r<(int)res.size())&& \
						(new_c>=0)&&(new_c<(int)res[0].size())&& \
						(res[new_r][new_c]<0) ){
					res[new_r][new_c] = res[r][c] + 1;
					q.push({new_r, new_c});
				}
			}
		}

		return res;
    }
};
