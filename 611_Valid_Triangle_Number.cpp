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
private:
	bool isTriangle(int a, int b, int c){// presume c >= max(a, b)
		return a+b>c;
	}
public:
    int triangleNumber(vector<int>& nums) {
		if(nums.size()<3) return 0;
		int res = 0;
		vector<int> dp(1002, 0);//dp[1001] stores the count of the sum of any pair of sides that is greater than 1000
		// sort nums
		std::sort(nums.begin(), nums.end());

		// find valid triangles
		for(int i=2; i<(int)nums.size(); ++i){
			int j = i-1;
			// find triangles of (a, b, i) where a<j and b<j
			for(int k=nums[i]+1; k<1002; ++k){
				res += dp[k];
			}
			// find triangles of (k, j, i) where k<j
			for(int k=j-1; k>=0; --k){
				if(nums[k]+nums[j]>nums[i]){
					++dp[min(1001, nums[k]+nums[j])];
					++res;
				}
				else break;
			}
		}

		// return
		return res;
    }
};
