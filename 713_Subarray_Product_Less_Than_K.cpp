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
		int len = nums.size();

		// sliding window (O(n) in time and O(1) in space)
		int l = 0, r = 0;
		int p = 1;
		while(r<len){
			int temp_p = p * nums[r];
			if((temp_p/nums[r]==p)&&(temp_p<k)){
				// update res
				res += r + 1 - l;
				// update r
				++r;
				// update p
				p = temp_p;
			}
			else{
				// find the minial l where the product of nums[l:r+1] < k
				bool isFound = false;
				while(l<r){
					p /= nums[l];
					++l;
					temp_p = p * nums[r];
					if((temp_p/nums[r]==p)&&(temp_p<k)){
						p = temp_p;
						isFound = true;
						break;
					}
				}
				if(isFound){
					res += r + 1 - l;
					++r;
				}
				else{ // no valid subarray is found
					l = ++r;
					p = 1;
				}
			}
		}

		// return
		return res;
    }
};
