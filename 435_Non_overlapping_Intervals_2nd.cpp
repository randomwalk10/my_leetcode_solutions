/*
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Note:

You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-overlapping-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;

        int res = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs){
            return (lhs[0]==rhs[0])?lhs[1]<rhs[1]:lhs[0]<rhs[0];
        });

        int temp_end = intervals[0][1];
        for (size_t i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i][0]>=temp_end) temp_end = intervals[i][1];
            else{
                temp_end = min(temp_end, intervals[i][1]);
                ++res;
            }
        }

        return res;
    }
};