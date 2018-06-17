/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> out;
		vector<int> path;
		this->combinationSum(candidates, target, path, out, 0);
		return out;
    }
private:
    void combinationSum(vector<int>& candidates, int target, vector<int> &path, \
			vector<vector<int>> &out, int base_index) {
		if(target==0){
			out.push_back(path);
			return;
		}
		for(int i=base_index; i<(int)candidates.size(); ++i){
			if(target>=candidates[i]){
				path.push_back(candidates[i]);
				this->combinationSum(candidates, target-candidates[i], path, out, i);
				path.pop_back();
			}
		}
    }
};
