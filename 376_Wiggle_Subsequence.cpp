/*
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Example 1:

Input: [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence.
Example 2:

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
Example 3:

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?

*/
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
		if(nums.empty()) return 0;
		int res = 1;
		vector<int> dp_cnt(nums.size(), 1);
		vector<int> dp_trend(nums.size(), 0);//1: positive lately; -1: negative lately; 0: both

		for(int i=0; i<(int)nums.size(); ++i){
			for(int prev_i=0; prev_i<i; ++prev_i){
				if(dp_cnt[prev_i]>=dp_cnt[i]){
					if((dp_trend[prev_i]==0)&&(nums[prev_i]!=nums[i])){
						dp_cnt[i] = dp_cnt[prev_i] + 1;
						dp_trend[i] = (nums[i]>nums[prev_i]) ? 1 : -1;
					}
					else if((dp_trend[prev_i]==1)&&(nums[prev_i]>nums[i])){
						dp_cnt[i] = dp_cnt[prev_i] + 1;
						dp_trend[i] = -1;
					}
					else if((dp_trend[prev_i]==-1)&&(nums[prev_i]<nums[i])){
						dp_cnt[i] = dp_cnt[prev_i] + 1;
						dp_trend[i] = 1;
					}
				}
				else if(dp_cnt[prev_i]+1==dp_cnt[i]){
					if(dp_trend[i]==1){
						if( (nums[prev_i]>nums[i]) && \
								(dp_trend[prev_i]!=-1) )
							dp_trend[i] = 0;
					}
					else if(dp_trend[i]==-1){
						if( (nums[prev_i]<nums[i]) && \
								(dp_trend[prev_i]!=1) )
							dp_trend[i] = 0;
					}
				}
			}

			res = (dp_cnt[i]>res) ? dp_cnt[i] : res;
		}

		return res;
    }
};
