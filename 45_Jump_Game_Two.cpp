/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
		if(nums.size()<2) return 0;
		int step = 0;
		int cur_reach = nums[0];
		int next_reach = cur_reach;
		for(int i=0; i<(int)nums.size(); ++i){
			if(i<=cur_reach){
				next_reach = ((i+nums[i])>next_reach) ? (i+nums[i]) : next_reach;
			}
			if((i==cur_reach)||(i==(int)(nums.size()-1))){
				cur_reach = next_reach;
				step++;
			}
		}
		return step;
    }
};
