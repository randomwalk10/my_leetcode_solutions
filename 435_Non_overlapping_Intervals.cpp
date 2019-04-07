/*
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note:

You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
Example 1:

Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:

Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool myCompare(Interval& a, Interval& b){
	return a.end < b.end;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
		if(intervals.empty()) return 0;
		// sort intervals by end in ascending order
		std::sort(intervals.begin(), intervals.end(), myCompare);

		// find maximal non-overlapping intervals by greedy algorithm
		int max_num = 1;
		int temp_end = intervals[0].end;
		for(int i=1; i<(int)intervals.size(); ++i){
			if(intervals[i].start>=temp_end){
				++max_num;
				temp_end = intervals[i].end;
			}
		}

		// return
		return intervals.size() - max_num;
    }
};
