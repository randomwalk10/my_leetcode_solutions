/*
You are given an integer array, nums, and an integer k. nums comprises of only 0's and 1's. In one move, you can choose two adjacent indices and swap their values.

Return the minimum number of moves required so that nums has k consecutive 1's.

 

Example 1:

Input: nums = [1,0,0,1,0,1], k = 2
Output: 1
Explanation: In 1 move, nums could be [1,0,0,0,1,1] and have 2 consecutive 1's.
Example 2:

Input: nums = [1,0,0,0,0,0,1,1], k = 3
Output: 5
Explanation: In 5 moves, the leftmost 1 can be shifted right until nums = [0,0,0,0,0,1,1,1].
Example 3:

Input: nums = [1,1,0,1], k = 2
Output: 0
Explanation: nums already has 2 consecutive 1's.
 

Constraints:

1 <= nums.length <= 105
nums[i] is 0 or 1.
1 <= k <= sum(nums)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
		vector<int> ones;
		vector<int> sums = {0};
		int res = -1;
		int cnt = -1;
		for (int i = 0; i < nums.size(); ++i) {
			if(nums[i]>0){
				++cnt;
				ones.push_back(i);
				sums.push_back(sums.back()+i-cnt);
			}
		}
		for (int i = 0; i + k - 1 < ones.size(); ++i) {
			int tmp = 0;
			int start;

			if(k%2){
				start = ones[(i + i + k - 1)/2] - (k - 1)/2;
			}
			else{
				start = ( ones[(i + i + k - 1)/2] + ones[(i + i + k -1)/2+1] ) / 2 - (k/2) + 1;
			}

			tmp += sums[i] + (start - i)*(k>>1) - sums[i+(k>>1)];
			tmp += sums[i+k] - sums[i+(k>>1)] + (i - start)*(k>>1);
			if(k%2) tmp += i - start;

			res = (res>=0)?min(res, tmp):tmp;
		}
		return res;
    }
};
