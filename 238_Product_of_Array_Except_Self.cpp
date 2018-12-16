/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> res(n, 1);
		int product1=1;
		int product2=1;

		//forward and backward
		for(int i=0; i<n; ++i){
			int r_i = n-1-i;

			res[i] *= product1;
			res[r_i] *= product2;

			product1 *= nums[i];
			product2 *= nums[r_i];
		}

		return res;
    }
};
