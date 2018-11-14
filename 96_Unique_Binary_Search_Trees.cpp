/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
		vector<int> dp(n+1, 0);
		dp[0]=1;

		for(int i=1; i<=n; ++i){
			for(int l=0; l<i; ++l){
				dp[i] += dp[l]*dp[i-l-1];
			}
		}

		return dp[n];
    }
};
