/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
	vector<vector<int>> diff = {{-1,0}, {1,0}, {0,-1}, {0,1}};
	int longestIncreasingPath(vector<vector<int>>& matrix, \
			vector<vector<int>>& path_lens, \
			int r, int c){
		stack<vector<int>> s;

		s.push({r, c});
		while(!s.empty()){
			int temp_r = s.top()[0];
			int temp_c = s.top()[1];
			int temp_len = 1;
			//search for neighbors
			for(int i=0; i<(int)diff.size(); ++i){
				int new_r = temp_r + diff[i][0];
				int new_c = temp_c + diff[i][1];
				if( (new_r>=0)&&(new_r<(int)matrix.size())&& \
						(new_c>=0)&&(new_c<(int)matrix[0].size())&& \
						(matrix[new_r][new_c]>matrix[temp_r][temp_c]) ){
					if(path_lens[new_r][new_c]>0)
						temp_len = max(temp_len,
								path_lens[new_r][new_c]+1);
					else
						s.push({new_r, new_c});
				}
			}
			//if no new neighbors, calculate for path_lens[temp_r][temp_c]
			if( (temp_r==s.top()[0])&&(temp_c==s.top()[1]) ){
				s.pop();
				path_lens[temp_r][temp_c] = temp_len;
			}
		}

		return path_lens[r][c];
	}
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
		if(matrix.empty()) return 0;
		vector<vector<int>> path_lens(matrix.size(), vector<int>(matrix[0].size(), 0));
		int res=0;

		for(int r=0; r<(int)matrix.size(); ++r){
			for(int c=0; c<(int)matrix[0].size(); ++c){
				if(path_lens[r][c]==0){
					res = max(res, longestIncreasingPath(
								matrix, path_lens, r, c));
				}
			}
		}

		return res;
    }
};
