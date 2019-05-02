/*
Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:

Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.
*/

#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		if(nums.empty()) return 0;
		int res = 0;

		int r = -1;
		int start = 0;
		int p = 1;
		for(int i=0; i<(int)nums.size(); ++i){
			// prepare start and p
			if(r<i){ // nums[i:r+1] is not valid subarray
				start = i;
				p = 1;
			}
			else{
				start = r + 1;
				p = p / nums[i-1];
			}
			// update r and p
			for(int j=start; j<(int)nums.size(); ++j){
				if(p*nums[j]/nums[j]!=p) break; // integer overflow
				if(p*nums[j]>=k) break; // product of subarray nums[i:j+1] >= k
				r = j;
				p *= nums[j];
			}
			// update res
			if(r>=i) res += r - i + 1;
		}

		return res;
    }
};
