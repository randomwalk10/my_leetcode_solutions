/*
Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

Example 1:

Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:

Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.

Note:

The length sum of the given matchsticks is in the range of 0 to 10^9.
The length of the given matchstick array will not exceed 15.
*/
#include <vector>
#include <algorithm>
using namespace std;

bool myCompare(int a, int b){
	return a > b;
}

class Solution {
private:
	bool makesquare(vector<int>& nums, vector<int>& sums, int idx, int target){
		// exit condition
		if(idx==(int)nums.size()) return true;
		// try all 4 subsets
		for(int i=0; i<4; ++i){
			if(nums[idx]+sums[i]>target) continue;
			sums[i] += nums[idx];
			if(makesquare(nums, sums, idx+1, target)) return true;
			sums[i] -= nums[idx];
		}
		// return false
		return false;
	}
public:
    bool makesquare(vector<int>& nums) {
		// check input
		if( nums.size()<4 ) return false;
		// compute the sum of nums
		int target = 0;
		for(int i=0; i<(int)nums.size(); ++i){
			target += nums[i];
		}
		if(target%4) return false;
		target /= 4;
		// sort nums in descending order (to prune logic branches early)
		std::sort(nums.begin(), nums.end(), myCompare);
		// dfs
		vector<int> sums(4, 0);
		return makesquare(nums, sums, 0, target); 
    }
};
