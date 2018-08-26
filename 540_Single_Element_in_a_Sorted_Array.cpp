/*
Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
Note: Your solution should run in O(log n) time and O(1) space.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
		int l=0, r=nums.size()-1;
		int mid;

		while(l<r){
			mid = (l+r)/2;
			if( (nums[mid-1]!=nums[mid]) && \
					(nums[mid]!=nums[mid+1]) )
				return nums[mid];
			else if( nums[mid-1]==nums[mid] ){
				if( (mid-l)%2 ) l = mid+1;
				else r = mid-2;
			}
			else{
				if( (mid-l)%2 ) r = mid-1;
				else l = mid+2;
			}
		}

		return nums[l];
    }
};
