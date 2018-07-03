/*
Given an array S of n integers, find three integers in S such that
the sum is closest to a given number, target. Return the sum of the
three integers. You may assume that each input would have exactly
one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include <vector>
#include <algorithm>
using namespace std;

//time complexity O(n^2) much better than O(n^3) from naive method
class Solution {
private:
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int out = INT_MIN;
		//sort nums
		sort(nums.begin(), nums.end());
		//transverse all combinations
		for(int i=0; i<((int)nums.size()-2); ++i){
			int l = i+1;
			int r = (int)(nums.size()-1);
			while(r>l){
				int temp = nums[i] + nums[l] + nums[r];
				//update l and r
				if(temp==target) return temp;
				else if(temp>target) --r;
				else ++l;
				//update out
				if(out==INT_MIN) out = temp;
				else out = (abs(temp-target)<abs(out-target)) ? \
					temp : out;
			}
		}
		//return
		return out;
    }
};
