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
		int l = 0;
		int r = (int)nums.size() - 1;
		int m;
		while(l<=r){
			m = (l+r)>>1;
			if(nums[m] > target) r = m - 1;
			else if(nums[m] < target) l = m + 1;
			else return m;
		}
		return l;
    }
};
