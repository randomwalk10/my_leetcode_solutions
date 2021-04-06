/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into sets of k consecutive numbers
Return True if it is possible. Otherwise, return False.

 

Example 1:

Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
Example 2:

Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
Example 3:

Input: nums = [3,3,2,2,1,1], k = 3
Output: true
Example 4:

Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.
 

Constraints:

1 <= k <= nums.length <= 105
1 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-array-in-sets-of-k-consecutive-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
		map<int, int> m_cnt;

		for (int i = 0; i < nums.size(); ++i) {
			++m_cnt[nums[i]];
		}

		while(m_cnt.empty()==false){
			auto iter = m_cnt.begin();
			int base_int = iter->first;
			for (int i = 0; i < k; ++i) {
				if((iter==m_cnt.end())||(iter->first!=i+base_int)||(iter->second<=0)) return false;
				--iter->second;
				++iter;
			}
			for (int i = 0; i < k; ++i) {
				iter = m_cnt.begin();
				if(iter->second<=0) m_cnt.erase(iter);
				else break;
			}
		}

		return true;
    }
};
