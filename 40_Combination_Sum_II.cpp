/*
Given a collection of candidate numbers (candidates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void combinationSum2(vector<int>& candidates, int target,
			vector<int>& path, vector<vector<int>>& result, int idx) {
		if(target<0) return;
		else if(target==0){
			result.push_back(path);
			return;
		}
		else if(idx>=(int)candidates.size()) return;

		//skip duplicates
		int idx2=idx+1;
		while( (idx2<(int)candidates.size())&&(candidates[idx2]==candidates[idx]) ){
			idx2++;
		}

		//search
		int cnt = 0;
		combinationSum2(candidates, target, path, result, idx2);
		while(cnt<(idx2-idx)){
			path.push_back(candidates[idx]);
			target -= candidates[idx];
			combinationSum2(candidates, target, path, result, idx2);
			cnt++;
		}
		
		//recorver path
		while(cnt>0){
			path.pop_back();
			cnt--;
		}
	}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> out;
		vector<int> path;
		int idx = 0;

		std::sort(candidates.begin(), candidates.end());
		combinationSum2(candidates, target, path, out, idx);

		return out;
    }
};
