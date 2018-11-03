/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
	void permuteUnique(unordered_map<int, int>& count_map, \
			vector<vector<int>>& res, vector<int>& path, int N){
		if((int)path.size()==N){
			res.push_back(path);
			return;
		}

		for(unordered_map<int, int>::iterator iter = count_map.begin(); \
				iter != count_map.end(); ++iter){
			if(iter->second){
				path.push_back(iter->first);
				iter->second--;
				permuteUnique(count_map, res, path, N);
				iter->second++;
				path.pop_back();
			}
		}
	}
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
		unordered_map<int, int> count_map;
		vector<vector<int>> res;
		int N = nums.size();

		//fill count_map
		for(int i=0; i<(int)nums.size(); ++i){
			count_map[nums[i]] += 1;
		}

		//search for all permutations
		vector<int> path;
		permuteUnique(count_map, res, path, N); 

		return res;
    }
};
