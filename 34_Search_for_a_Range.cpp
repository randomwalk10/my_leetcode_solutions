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
		vector<int> result;
		if(nums.empty()){
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}

		int l, r, m;

		l = 0;
		r = (int)nums.size() - 1;
		m = (l+r)/2;
		while(l<r){
			if(nums[m]>target) r = m - 1;
			else if(nums[m]<target) l = m + 1;
			else if(m==0) break;
			else if(nums[m-1]!=target) break;
			else r = m - 1;
			m = (l+r)/2;
		}
		if(nums[m]!=target) m = -1;
		result.push_back(m);

		l = (m>-1) ? m : 0;
		r = (int)nums.size() - 1;
		m = (l+r)/2;
		while(l<r){
			if(nums[m]>target) r = m - 1;
			else if(nums[m]<target) l = m + 1;
			else if(m==(int)(nums.size()-1)) break;
			else if(nums[m+1]!=target) break;
			else l = m + 1;
			m = (l+r)/2;
		}
		if(nums[m]!=target) m = -1;
		result.push_back(m);

		return result;
    }
};
