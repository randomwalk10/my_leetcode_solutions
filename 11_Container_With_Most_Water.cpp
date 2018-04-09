/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int max_area = 0;
		int l = 0;
		int r = (int)height.size() - 1;
		while(l<r){
			int temp = (r-l)*((height[l]<height[r])?height[l]:height[r]);
			max_area = (max_area>temp)?max_area:temp;
			if(height[l]<height[r]) l++;
			else r--;
		}
		return max_area;
    }
};
