/*
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
 

Note:

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
*/

#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
		if(A.empty()||B.empty()) return 0;
		int res = 0;
		int len_a = A.size(), len_b = B.size();
		int prev;
		vector<int> dp(len_b+1, 0); // the maximal length of subarray starting at B[j], for j in [0, len_b]

		// dynamic programming
		for(int i=len_a-1; i>=0; --i){
			// reset prev
			prev = 0;
			// iterate through B
			for(int j=len_b-1; j>=0; --j){
				int tmp = dp[j]; // save for prev at the end of this loop
				// update dp[j] and res
				if(A[i]==B[j]){
					dp[j] = 1 + prev;
					res = max(res, dp[j]);
				}
				else{
					dp[j] = 0;
				}
				// update prev
				prev = tmp; // save for j-1
			}
		}

		// return
		return res;
    }
};
