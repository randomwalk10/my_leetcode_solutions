/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int max_val = INT_MIN;
		bool connectFlag = false;
		int sum = 0;

		for(size_t i=0; i<nums.size(); ++i){
			if(nums[i]<=0){
				if(connectFlag){
					if( (sum+nums[i]) <= 0 ) connectFlag = false;
					else sum += nums[i];
				}
				else{
					max_val = (nums[i] > max_val) ? nums[i] : max_val;
				}
			}
			else{
				if(connectFlag) sum += nums[i];
				else{
					connectFlag = true;
					sum = nums[i];
				}
				max_val = (sum > max_val) ? sum : max_val;
			}
		}

		return max_val;
    }
};
