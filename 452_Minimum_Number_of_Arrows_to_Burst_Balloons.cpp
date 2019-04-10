/*
There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
*/
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool myCompare(pair<int, int>& a, pair<int, int>& b){
	return a.first < b.first;
}

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
		// return 0 if points is empty
		if(points.empty()) return 0;
		// sort points by start in ascending order
		std::sort(points.begin(), points.end(), myCompare);
		// greedy agorithm
		int res = 1;
		int temp_end = points[0].second;
		for(int i=1; i<(int)points.size(); ++i){
			if(points[i].first>temp_end){
				++res;
				temp_end = points[i].second;
			}
			else{
				temp_end = (points[i].second<temp_end)?points[i].second:temp_end;
			}
		}
		// return
		return res;
    }
};
