/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
		int thresh = (int)(nums.size()) / 3;
		vector<int> out;
		int mask = 0;


		for(int i=0; i<32; i++){
			//create candidate
			vector<int> candidates;
			if(0==i){
				candidates.push_back(1);
				candidates.push_back(0);
			}
			else{
				for(vector<int>::iterator iter=out.begin();
						iter!=out.end(); ++iter){
					candidates.push_back( *iter + (1<<i) );
					candidates.push_back( *iter + (0<<i) );
				}
			}
			//count
			mask |= (1<<i);
			out.clear();
			for(vector<int>::iterator iter=candidates.begin();
					iter!=candidates.end(); ++iter){
				int cnt = 0;
				for(int j=0; j<(int)nums.size(); ++j){
					if((nums[j]&mask)==*iter){
						cnt++;
					}
				}
				if(cnt>thresh) out.push_back(*iter);
			}
			//decide whether to terminate or not
			if(out.empty()) return out;
		}

		return out;
    }
};
