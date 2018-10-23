/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		if(nums.empty()) return 0;
		unordered_set<int> _set;
		int max_cnt = 1;

		for(size_t i=0; i<nums.size(); ++i){
			_set.insert(nums[i]);
		}

		for(unordered_set<int>::iterator iter=_set.begin();
				iter!=_set.end(); ++iter){
			if(_set.find(*iter-1)==_set.end()){
				int temp_cnt = 1;
				int curNum = *iter;
				while(_set.find(++curNum)!=_set.end()){
					temp_cnt++;
				}
				max_cnt = (temp_cnt>max_cnt) ? temp_cnt : max_cnt;
			}
		}

		return max_cnt;
    }
};
