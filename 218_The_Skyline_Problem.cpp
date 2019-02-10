/*
 A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

 The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
*/

#include <vector>
#include <utility>
#include <map>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		//find critical points
		map<int, pair<vector<int>, vector<int>>> cpoints;
		for(int i=0; i<(int)buildings.size(); ++i){
			int start_pos = buildings[i][0];
			int end_pos = buildings[i][1];
			cpoints[start_pos].first.push_back(i);//first of the pair is a list of rect indices starting at position start_pos
			cpoints[end_pos].second.push_back(i);//second of the pair is a list of rect indices ending at position end_pos
		}
		
		//find max height at critical points
		vector<pair<int, int>> res;//heights at each critical points
		map<int, int> height_counts;//counts of each height
		int prev_h = -1;//previous height
		for(map<int, pair<vector<int>, vector<int>>>::iterator kp = \
				cpoints.begin(); kp != cpoints.end(); ++kp){
			//add heights
			for(vector<int>::iterator rect_idx = kp->second.first.begin(); \
					rect_idx != kp->second.first.end(); ++rect_idx){
				int height = buildings[*rect_idx][2];
				map<int, int>::iterator count = height_counts.find(height);
				if(height_counts.end()==count)
					height_counts[height] = 1;
				else
					count->second += 1;
			}
			//remove heights
			for(vector<int>::iterator rect_idx = kp->second.second.begin(); \
					rect_idx != kp->second.second.end(); ++rect_idx){
				int height = buildings[*rect_idx][2];
				map<int, int>::iterator count = height_counts.find(height);
				if(count->second==1)
					height_counts.erase(count);
				else
					count->second -= 1;
			}
			//update height with the maxmal value at each critical point
			int cur_h = 0;
			if(!height_counts.empty()){
				map<int, int>::iterator count = height_counts.end();
				--count;//point to the last key
				cur_h = count->first;
			}
			//avoid duplicates and update res
			if(cur_h!=prev_h){
				res.push_back({kp->first, cur_h});
				prev_h = cur_h;
			}
		}
		//return
		return res;
    }
};
