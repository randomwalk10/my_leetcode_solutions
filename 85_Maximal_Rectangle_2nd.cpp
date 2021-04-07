/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = []
Output: 0
Example 3:

Input: matrix = [["0"]]
Output: 0
Example 4:

Input: matrix = [["1"]]
Output: 1
Example 5:

Input: matrix = [["0","0"]]
Output: 0
 

Constraints:

rows == matrix.length
cols == matrix[i].length
0 <= row, cols <= 200
matrix[i][j] is '0' or '1'.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-rectangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
		if(matrix.empty()||matrix[0].empty()) return 0;
		int res = 0;
		vector<int> h(matrix[0].size(), 0);
		vector<int> w(matrix[0].size(), 0);
		for (int r = 0; r < matrix.size(); ++r) {
			stack<int> lows;
			for (int c = 0; c < matrix[0].size(); ++c) {
				if(0==r){
					h[c] = (matrix[r][c]=='0')?0:1;
				}
				else{
					h[c] = (matrix[r][c]=='0')?0:h[c]+1;
				}
				while((false==lows.empty())&&(h[lows.top()]>=h[c])){
					lows.pop();
				}
				if(lows.empty()){
					w[c] = c + 1;
				}
				else{
					w[c] = c - lows.top();
				}
				lows.push(c);
			}
			while(false==lows.empty()) lows.pop();
			for (int c = matrix[0].size()-1; c >= 0; --c) {
				while((false==lows.empty())&&(h[lows.top()]>=h[c])){
					lows.pop();
				}
				if(lows.empty()){
					w[c] += matrix[0].size() - c - 1;
				}
				else{
					w[c] += lows.top() - c - 1;
				}
				res = max(res, w[c]*h[c]);
				lows.push(c);
			}
		}
		return res;
    }
};
