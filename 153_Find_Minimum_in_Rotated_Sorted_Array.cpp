/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
		if(nums.size()<2) return nums[0];
		else if(nums[0]<nums[nums.size()-1]) return nums[0];

		int l = 0;
		int r = nums.size()-1;
		int max_num = nums[l];
		int min_num = nums[r];

		while(r-l>1){
			int m = (l+r)/2;
			if(nums[m]<min_num){
				r = m;
				min_num = nums[m];
			}
			else if(nums[m]>max_num){
				l = m;
				max_num = nums[m];
			}
			else{
				//since elements in nums are unique, nothing to do here
			}
		}

		return nums[r];
    }
};
