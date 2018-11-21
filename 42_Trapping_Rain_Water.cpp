/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
#include <vector>
#include <deque>
using namespace std;

class Solution {
private:
	void updateQueue(deque<int>& q, vector<int>& h, int i){
		while( (!q.empty()) && \
				( h[i]>=h[q.back()] ) )
			q.pop_back();
		q.push_back(i);
	}
public:
    int trap(vector<int>& height) {
		if(height.empty()) return 0;
		vector<int> water(height.size(), 0);
		deque<int> local_max;
		deque<int> r_local_max;
		int res = 0;

		//fill in local_max and r_local_max
		for(int i=0; i<(int)height.size(); ++i){
			int r_i = (int)height.size()-1-i;
			if(i==((int)height.size()-1)){
				updateQueue(local_max, height, i);
				updateQueue(r_local_max, height, r_i);
			}
			else{
				if(height[i]>height[i+1]){
					updateQueue(local_max, height, i);
				}
				if(height[r_i]>height[r_i-1]){
					updateQueue(r_local_max, height, r_i);
				}
			}
		}
		//fill in water from local max
		for(int i=0; i<(int)height.size(); ++i){
			water[i] = max(height[i], height[local_max.front()]);
			if(i==local_max.front())
				local_max.pop_front();
		}
		//fill in water from r_local_max
		for(int r_i=(int)height.size()-1; r_i>=0; --r_i){
			water[r_i] = max(height[r_i], \
					min(water[r_i], height[r_local_max.front()]));
			res += water[r_i] - height[r_i];
			if(r_i==r_local_max.front())
				r_local_max.pop_front();
		}

		return res;
    }
};
