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
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
		if(matrix.empty()) return 0;
		int res = 0;
		stack<int> s;
		vector<int> heights(matrix[0].size()+1, 0);
		int l;

		for(int r=0; r<(int)matrix.size(); ++r){
			//update heights
			for(int c=0; c<(int)heights.size(); ++c){
				if(c!=((int)heights.size()-1)){
					if(matrix[r][c]!='0'){
						heights[c] += 1;
					}
					else{
						heights[c] = 0;
					}
				}
				//update res
				if( s.empty() || (heights[s.top()]<=heights[c]) ){
					if(heights[c]){
						if(s.empty()) l = c; 
						s.push(c);
					}
				}
				else{
					while( (!s.empty()) && (heights[s.top()]>heights[c]) ){
						int idx = s.top();
						s.pop();
						int temp = s.empty() ? heights[idx]*(c-l) : \
								   heights[idx]*(c-s.top()-1);
						res = max(res, temp);
					}
					if(heights[c]) s.push(c);
				}
			}
		}

		return res;
    }
};
