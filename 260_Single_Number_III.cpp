/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
		int temp = 0;
		size_t bit_pos = 0;
		for(size_t i=0; i<nums.size(); ++i) temp ^= nums[i];
		for(size_t i=0; i<32; ++i){
			if(temp&(1<<i)){
				bit_pos = i;
				break;
			}
		}
		int mask = 1<<bit_pos;
		int temp1 = 0, temp2 = 0;
		for(size_t i=0; i<nums.size(); ++i){
			if(nums[i]&mask) temp1 ^= nums[i];
			else temp2 ^= nums[i];
		}

		vector<int> output;
		output.push_back(temp1);
		output.push_back(temp2);
		return output;
    }
};
