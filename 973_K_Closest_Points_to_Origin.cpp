/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

Example 1:


Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 

Constraints:

1 <= k <= points.length <= 104
-104 < xi, yi < 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-closest-points-to-origin
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <queue>
using namespace std;

class closer
{
	public:
		bool operator() (pair<int, int>& lhs, pair<int, int>& rhs){
			return lhs.first*lhs.first+lhs.second*lhs.second < rhs.first*rhs.first+rhs.second*rhs.second;
		}
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		std::priority_queue<pair<int, int>, vector<pair<int, int>>, closer> q;
		for (auto pt:points) {
			q.push({pt[0], pt[1]});
			if(q.size()>k) q.pop();
		}
		vector<vector<int>> res;
		while(q.empty()==false){
			res.push_back({q.top().first, q.top().second});
			q.pop();
		}
		return res;
    }
};
