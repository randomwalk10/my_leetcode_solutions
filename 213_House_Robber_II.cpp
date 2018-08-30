/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
		if(nums.empty()) return 0;
		else if(nums.size()<2) return nums[0];

		int select;
		int skip;
		int temp;
		int max_rob;

		//index 0 is not robbed
		select = nums[1];
		skip = 0;
		for(size_t i=2; i<nums.size(); ++i){
			temp = select;
			select = skip + nums[i];
			skip = temp > skip ? temp : skip;
		}
		max_rob = (select > skip) ? select : skip;
		//index 0 is robbed
		select = nums[0];
		skip = nums[0];
		for(size_t i=2; i<nums.size(); ++i){
			temp = select;
			select = skip + nums[i];
			skip = temp > skip ? temp : skip;
		}
		max_rob = (skip > max_rob) ? skip : max_rob;

		return max_rob;
    }
};
