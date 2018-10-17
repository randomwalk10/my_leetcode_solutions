/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/
#include <vector>
using namespace std;

/* recursion slow...*/
/*
class Solution {
private:
	void combinationSum4(vector<int>& nums, int target, int& res){
		if(target<0) return;
		if(target==0){
			res++;
			return;
		}

		for(size_t i=0; i<nums.size(); ++i){
			this->combinationSum4(nums, target-nums[i], res);
		}

		return;
	}
public:
    int combinationSum4(vector<int>& nums, int target) {
		int res=0;
		this->combinationSum4(nums, target, res);
		return res;
    }
};
*/


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp(target+1, 0);
		dp[0] = 1;

		for(int i=1; i<=target; ++i){
			for(size_t j=0; j<nums.size(); ++j){
				if(i>=nums[j]){
					dp[i] += dp[i-nums[j]];
				}
			}
		}

		return dp[target];
    }
};
