/*
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:

Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
		unordered_map<int, int> dict;
		int out = 0;

		for(size_t i=0; i<nums.size(); ++i){
			if(dict.end()==dict.find(nums[i]))
				dict[nums[i]] = 1;
			else
				dict[nums[i]] += 1;
		}

		for(unordered_map<int, int>::iterator iter = \
				dict.begin(); iter != dict.end(); ++iter){
			if(dict.end()!=dict.find(iter->first-1))
				out = max(iter->second + dict[iter->first-1], out);
		}

		return out;
    }
};
