/*
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:

Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:

The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
		if(nums.size()<3) return 0;
		int res = 0;
		// sort nums
		std::sort(nums.begin(), nums.end());

		// find valid triangles
		for(int i=nums.size()-1; i>=2; --i){
			int j = i - 1; //  the midle side
			int k = 0; // the shortest side
			while(j>k){
				if(nums[j]+nums[k]>nums[i]){
					res += j - k;
					--j;
				}
				else{
					++k;
				}
			}
		}

		// return
		return res;
    }
};
