/*
A majority element is an element that makes up more than half of the items in an array. Given a positive integers array, find the majority element. If there is no majority element, return -1. Do this in O(N) time and O(1) space.

Example 1:

Input: [1,2,5,9,5,9,5,5,5]
Output: 5
 

Example 2:

Input: [3,2]
Output: -1
 

Example 3:

Input: [2,2,1,1,1,2,2]
Output: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-majority-element-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		unordered_map<int, int> m;
		int max_cnt = 0;
		int res = -1;
		int i;
		for (i = 0; i < (int)nums.size(); ++i) {
			int temp = ++m[nums[i]];
			if(temp>max_cnt){
				res = nums[i];
				max_cnt = max(temp, max_cnt);
			}
		}
		return (max_cnt>(nums.size()>>1))?res:-1;
    }
};
