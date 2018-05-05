/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> output;
		vector<int> temp;
		output.push_back(temp);
		for(int i = (int)nums.size()-1; i>=0; --i){
			int new_val = nums[i];
			vector<vector<int>> backup = output;
			for(vector<vector<int>>::iterator iter = \
					output.begin(); iter != output.end(); \
					++iter){
				iter->push_back(new_val);
			}
			for(vector<vector<int>>::iterator iter = \
					backup.begin(); iter != backup.end(); \
					++iter){
				output.push_back(*iter);
			}
		}
		return output;
    }
};
