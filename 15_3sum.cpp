/*
Given an array S of n integers, are there elements a, b, c in S
such that a + b + c = 0? Find all unique triplets in the array
which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> zero_vector;
		if(nums.size()<3) return zero_vector;
		sort(nums.begin(), nums.end());
		for(size_t i=0; i<nums.size()-2; ++i){
			if( (i>0) && (nums[i]==nums[i-1]) ) continue;
			size_t l = i+1;
			size_t r = nums.size() - 1;
			while(l<r){
				int sum = nums[i] + nums[l] + nums[r];
				if(sum<0) ++l;
				else if(sum>0) --r;
				else{
					vector<int> new_zero;
					new_zero.push_back(nums[i]);
					new_zero.push_back(nums[l]);
					new_zero.push_back(nums[r]);
					zero_vector.push_back(new_zero);
					while( (l<r) && (nums[l]==nums[l+1]) ) ++l;
					while( (l<r) && (nums[r]==nums[r-1]) ) --r;
					++l;
					--r;
				}
			}
		}
		return zero_vector;
    }
};
