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
		unordered_map<int, vector<vector<int>>> dict;//store combinations with sum < target
		vector<vector<int>> out;
		for(size_t i=0; i<candidates.size(); ++i){
			//update out
			int max_num = target/candidates[i];
			if(target%candidates[i]==0){
				vector<int> temp(max_num, candidates[i]);
				out.push_back(temp);
				max_num--;
			}
			while(max_num){
				unordered_map<int, vector<vector<int>>>::iterator iter = 
					dict.find(target-max_num*candidates[i]);
				if(iter!=dict.end()){
					vector<int> temp(max_num, candidates[i]);
					for(size_t j=0; j<iter->second.size(); ++j){
						vector<int> temp2 = iter->second[j];
						temp2.insert(temp2.end(), temp.begin(), temp.end());
						out.push_back(temp2);
					}
				}
				max_num--;
			}
			//update dict with candidates[i]
			unordered_map<int, vector<vector<int>>> temp_dict;
			max_num = target/candidates[i];
			if(target%candidates[i]==0) max_num--;
			while(max_num){
				vector<int> temp(max_num, candidates[i]);
				if(temp_dict.find(max_num*candidates[i])!=temp_dict.end())
					temp_dict[max_num*candidates[i]].push_back(temp);
				else{
					vector<vector<int>> temp_vector = {temp};
					temp_dict[max_num*candidates[i]] = temp_vector;
				}
				int temp_target = target-1;
				while(temp_target>(max_num*candidates[i])){
					unordered_map<int, vector<vector<int>>>::iterator iter = 
						dict.find(temp_target-max_num*candidates[i]);
					if(iter!=dict.end()){
						for(size_t j=0; j<iter->second.size(); ++j){
							vector<int> temp2 = iter->second[j];
							temp2.insert(temp2.end(), temp.begin(), temp.end());
							if(temp_dict.find(temp_target)!=temp_dict.end()){
								temp_dict[temp_target].push_back(temp2);
							}
							else{
								vector<vector<int>> temp_vector = {temp2};
								temp_dict[temp_target] = temp_vector;
							}
						}
					}
					temp_target--;
				}
				max_num--;
			}
			for(int temp_target = 1; temp_target<target; ++temp_target){
				if(temp_dict.find(temp_target)!=temp_dict.end()){
					if(dict.find(temp_target)!=dict.end()){
						dict[temp_target].insert(dict[temp_target].end(), \
								temp_dict[temp_target].begin(), \
								temp_dict[temp_target].end());
					}
					else{
						dict[temp_target] = temp_dict[temp_target];
					}
				}
			}
		}
		return out;
    }
};
