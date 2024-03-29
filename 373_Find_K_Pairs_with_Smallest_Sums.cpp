/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
 

Constraints:

1 <= nums1.length, nums2.length <= 104
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in ascending order.
1 <= k <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <queue>
using namespace std;

class Compare{
	public:
		bool operator() (vector<int>& lhs, vector<int>& rhs){
			return lhs[0]+lhs[1]<rhs[0]+rhs[1];
		}
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		int tmp = nums1.size() * nums2.size();
		k = min(k, tmp);
		vector<vector<int>> res(k);
		std::priority_queue<vector<int>, vector<vector<int>>, Compare> q;
		for (int i = 0; i < nums1.size(); ++i) {
			for (int j = 0; j < nums2.size(); ++j) {
				q.push({nums1[i], nums2[j]});
				if(q.size()>k) q.pop();
			}
		}
		while(q.size()>0){
			res[q.size()-1] = q.top();
			q.pop();
		}
		return res;
    }
};
