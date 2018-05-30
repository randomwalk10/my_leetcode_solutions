/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 1:

Input: [1,3,5,6], 0
Output: 0
*/
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		if(nums.front()>=target) return 0;
		else if(nums.back()==target) return nums.size() - 1;
		else if(nums.back()<target) return nums.size();
		int l = 0;//nums[l]<target
		int r = nums.size() - 1;//nums[r]>target
		int m;
		while(r-l>1){
			m = (l+r)>>1;
			if(nums[m] < target) l = m;
			else if(nums[m] > target) r = m;
			else return m;
		}
		return r;
    }
};
