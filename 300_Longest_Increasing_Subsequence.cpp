/*
 Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?


*/
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if(n<=1) return n;

		vector<int> dp(n, 0);//store smallest tail number in subsequences of length at index length - 1
		int res = 1;//length of longest subsequences

		for(int i=0; i<n; ++i){
			if(0==i){
				dp[0] = nums[0];
			}
			else{
				//perform binary search
				int l = 0;//where nums[i]>dp[l]
				int h = res-1;//where nums[i]<=dp[h]
				if(nums[i]<=dp[l])
					dp[l] = nums[i];
				else if(nums[i]>dp[h]){
					dp[h+1] = nums[i];
					++res;
				}
				else{
					//find max l
					while(l+1<h){
						int m = (l+h)/2;
						if(nums[i]>dp[m]) l = m;
						else h = m;
					}
					//update dp[l+1]
					dp[l+1] = (nums[i]<dp[l+1]) ? nums[i] : dp[l+1];
				}
			}
		}

		return res;
    }
};
