/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		if(n<1) return vector<vector<int>>();
		vector<vector<int>> out(n, vector<int>(n, 0));
		int l=0, r=n-1;
		int cnt=0;
		while(l<=r){
			//fill out
			for(int i=l; i<=r; ++i)
				out[l][i] = ++cnt;
			for(int i=l+1; i<=r; ++i)
				out[i][r] = ++cnt;
			for(int i=r-1; i>=l; --i)
				out[r][i] = ++cnt;
			for(int i=r-1; i>l; --i)
				out[i][l] = ++cnt;
			//update l, r
			l++;
			r--;
		}
		return out;
    }
};
