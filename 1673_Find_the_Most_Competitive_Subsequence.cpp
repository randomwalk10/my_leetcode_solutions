/*
Given an integer array nums and a positive integer k, return the most competitive resuence of nums of size k.

An array's resuence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a resuence a is more competitive than a resuence b (of the same length) if in the first position where a and b differ, resuence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.

 

Example 1:

Input: nums = [3,5,2,6], k = 2
Output: [2,6]
Explanation: Among the set of every possible resuence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.
Example 2:

Input: nums = [2,4,3,3,5,4,9,6], k = 4
Output: [2,3,3,4]
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
1 <= k <= nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-most-competitive-resuence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
		vector<int> res;

		for (int i = 0; i < nums.size(); ++i) {
			while((nums.size()-i>k-res.size())&&(false==res.empty())&&(res.back()>nums[i])){
				res.pop_back();
			}
			if(res.size()<k) res.push_back(nums[i]);
		}

		return res;
    }
};
