/*
You are driving a vehicle that has capacity empty seats initially available for passengers.  The vehicle only drives east (ie. it cannot turn around and drive west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the i-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 

 

Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
Example 3:

Input: trips = [[2,1,5],[3,5,7]], capacity = 3
Output: true
Example 4:

Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
Output: true
 
 

Constraints:

trips.length <= 1000
trips[i].length == 3
1 <= trips[i][0] <= 100
0 <= trips[i][1] < trips[i][2] <= 1000
1 <= capacity <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/car-pooling
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
		map<int, int> m_cnt;

		for (size_t i = 0; i < trips.size(); ++i) {
			int psg_num = trips[i][0];
			int start = trips[i][1];
			int end = trips[i][2];

			map<int, int>::iterator start_iter = m_cnt.find(start);
			if(start_iter==m_cnt.end()){
				m_cnt[start] = psg_num;
				start_iter = m_cnt.find(start);
				if(start_iter!=m_cnt.begin()){
					map<int, int>::iterator prev_iter = start_iter;
					--prev_iter;
					start_iter->second += prev_iter->second;
				}
			}
			else start_iter->second += psg_num;
			if(capacity<start_iter->second) return false;

			map<int, int>::iterator end_iter = m_cnt.find(end);
			if(end_iter==m_cnt.end()){
				m_cnt[end] = 0;
				end_iter = m_cnt.find(end);
				map<int, int>::iterator prev_iter = end_iter;
				--prev_iter;
				if(prev_iter==start_iter) end_iter->second = prev_iter->second - psg_num;
				else end_iter->second += prev_iter->second;
			}
			if(capacity<end_iter->second) return false;

			map<int, int>::iterator cur_iter = start_iter;
			++cur_iter;
			while(cur_iter!=end_iter){
				cur_iter->second += psg_num;
				if(capacity<cur_iter->second) return false;
				++cur_iter;
			}
		}

		return true;
    }
};
