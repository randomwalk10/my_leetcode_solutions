/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		if( (nums.empty()) || (nums.front()>target) || (nums.back()<target) ){
			vector<int> error(2, -1);
			return error;
		}

		vector<int> output;
		//find the left index
		if(nums.front()==target) output.push_back(0);
		else{
			//nums[l] < target, nums[r] >= target
			int l = 0;
			int r = nums.size() - 1;
			while( (r-l)>1 ){
				int m = (l+r)/2;
				if(nums[m]>=target) r = m;
				else l = m;
			}
			if(nums[r]==target) output.push_back(r);
			else{
				vector<int> error(2, -1);
				return error;
			}
		}

		//find the right index
		if(nums.back()==target) output.push_back(nums.size()-1);
		else{
			//nums[l] <= target, nums[r] > target
			int l = 0;
			int r = nums.size() - 1;
			while( (r-l)>1 ){
				int m = (l+r)/2;
				if(nums[m]<=target) l = m;
				else r = m;
			}
			if(nums[l]==target) output.push_back(l);
			else{
				vector<int> error(2, -1);
				return error;
			}
		}
		//return
		return output;
    }
};
