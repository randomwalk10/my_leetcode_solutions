/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
		vector<int> dp(n);
		dp[0] = 1;
		int t2=0, t3=0, t5=0;
		int dp2, dp3, dp5;
		for(int i=1; i<n; ++i){
			dp2 = dp[t2]*2;
			dp3 = dp[t3]*3;
			dp5 = dp[t5]*5;
			if( dp2<=dp3 && dp2<=dp5 ){
				t2++;
				dp[i] = dp2;
			}
			if( dp3<=dp2 && dp3<=dp5 ){
				t3++;
				dp[i] = dp3;
			}
			if( dp5<=dp2 && dp5<=dp3 ){
				t5++;
				dp[i] = dp5;
			}
		}
		return dp[n-1];
	}
};
