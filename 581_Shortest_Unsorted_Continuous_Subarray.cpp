/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:

Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:

Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
		if(nums.size()<2) return 0;
		int l = 0;
		int r = nums.size()-1;
		//find the subarray that is not in ascending order
		while(l<(int)nums.size()-1){
			if(nums[l]<=nums[l+1]) l++;
			else break;
		}
		while(r>0){
			if(nums[r-1]<=nums[r]) r--;
			else break;
		}
		if(l>=r) return 0;
		//find minimal and maxmal elements for subarray[l,...,r]
		int min_element = nums[l];
		int max_element = nums[r];
		for(int i=l; i<=r; ++i){
			min_element = min(nums[i], min_element);
			max_element = max(nums[i], max_element);
		}
		//expand this subarray to a minimal unsorted subarray
		int temp_l = 0;
		int temp_r = l;
		while(temp_l<temp_r){
			int temp_mid = (temp_l+temp_r)/2;
			if(nums[temp_mid]<=min_element) temp_l = temp_mid + 1;
			else temp_r = temp_mid;
		}
		l = temp_r;
		
		temp_l = r;
		temp_r = nums.size()-1;
		while(temp_l<temp_r){
			if(temp_l+1==temp_r){
				temp_l = (max_element>nums[temp_r]) ? temp_r : temp_l;
				break;
			}
			int temp_mid = (temp_l+temp_r)/2;
			if(nums[temp_mid]>=max_element) temp_r = temp_mid - 1;
			else temp_l = temp_mid;
		}
		r = temp_l;

		return 1+(r-l);
    }
};
