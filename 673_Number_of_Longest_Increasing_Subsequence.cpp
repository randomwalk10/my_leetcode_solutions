/*
Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:

Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
		if(nums.empty()) return 0;
		vector<int> max_length(nums.size(), 1);
		vector<int> count_seq(nums.size(), 1);
		int max_length_val = 1;

		for(int i=1; i<(int)nums.size(); ++i){
			for(int j=0; j<i; ++j){
				if(nums[i]>nums[j]){
					if(max_length[i]==max_length[j]+1){
						count_seq[i] += count_seq[j];
					}
					else if(max_length[i]<=max_length[j]){
						max_length[i] = max_length[j] + 1;
						max_length_val = (max_length[i]>max_length_val) ? \
										 max_length[i] : max_length_val;
						count_seq[i] = count_seq[j];
					}
				}
			}
		}

		int res = 0;
		for(int i=0; i<(int)nums.size(); ++i){
			if(max_length[i]==max_length_val){
				res += count_seq[i];
			}
		}

		return res;
    }
};
