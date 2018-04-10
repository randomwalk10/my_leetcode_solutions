/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		if(nums.empty()) return -1;
		if(nums.front() < nums.back()){
			if( (target >= nums.front()) && (target <= nums.back()) ){
				for(size_t i=0; i<nums.size(); ++i){
					if(target == nums[i]) return (int)i;
				}
			}
		}
		else{
			if(target >= nums.front()){
				for(size_t i=0; i<nums.size(); ++i){
					if(nums.front() > nums[i]) return -1;
					if(target<nums[i]) return -1;
					if(target==nums[i]) return (int)i;
				}
			}
			else if(target <= nums.back()){
				for(size_t i=nums.size()-1; i>=0; --i){
					if(nums.back() < nums[i]) return -1;
					if(target>nums[i]) return -1;
					if(target==nums[i]) return (int)i;
				}
			}
		}
		return -1;
    }
};
