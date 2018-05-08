/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int output = 0;
		for(size_t i=0; i<32; ++i){
			int cnt = 0;
			for(size_t j=0; j<nums.size(); ++j){
				if( (nums[j]>>i) & 0x1 ){
					cnt++;
					cnt %= 3;
				}
			}
			if(cnt) output |= (1<<i);
		}
		return output;
    }
};
