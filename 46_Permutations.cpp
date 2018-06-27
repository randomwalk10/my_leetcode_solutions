/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
#include <vector>
using namespace std;

class Solution {
private:
	void permute(vector<int> nums, vector<int> path, \
			vector<vector<int>> &result){
		if(nums.empty()){
			result.push_back(path);
			return;
		}
		for(size_t i=0; i<nums.size(); ++i){
			vector<int> reduced_nums = nums;
			reduced_nums.erase(reduced_nums.begin()+i);
			path.push_back(nums[i]);
			permute(reduced_nums, path, result);
			path.pop_back();
		}
	}

public:
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> out;
		vector<int> path;
		permute(nums, path, out);
		return out;
    }
};
