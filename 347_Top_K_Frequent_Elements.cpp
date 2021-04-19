/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Compare{
	public:
		bool operator() (pair<int, int>& lhs, pair<int, int>& rhs){
			return lhs.second < rhs.second;
		}
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		std::priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
		unordered_map<int, int> m;
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			m[nums[i]] += 1;
		}
		for (auto iter = m.begin(); iter != m.end(); ++iter){
			q.push({iter->first, iter->second});
		}
		while(res.size()<k){
			res.push_back(q.top().first);
			q.pop();
		}
		return res;
    }
};
