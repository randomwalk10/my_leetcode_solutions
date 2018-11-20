/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
*/
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
		if(matrix.empty()) return 0;
		int res = 0;
		vector<int> heights(matrix[0].size(), 0);

		for(int r=0; r<(int)matrix.size(); ++r){
			for(int c=0; c<(int)matrix[0].size(); ++c){
				if(matrix[r][c]!='0'){
					//update res
					int min_height = heights[c]+1;
					int temp_c = c;
					while( (temp_c<(int)matrix[0].size()) && \
							(matrix[r][temp_c]!='0') ){
						min_height = min(min_height, heights[temp_c]+1);
						res = max(res, (temp_c-c+1) * min_height);
						temp_c++;
					}
					//update heights
					heights[c] += 1;
				}
				else{
					heights[c] = 0;
				}
			}
		}

		return res;
    }
};
