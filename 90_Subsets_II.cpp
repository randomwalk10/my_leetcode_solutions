/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> out;
		vector<int> temp;
		out.push_back(temp);

		std::sort(nums.begin(), nums.end());

		int i=0;
		int j;
		int prev_size;
		while(i<(int)nums.size()){
			j=i;
			while( (j<(int)nums.size()) && (nums[i]==nums[j]) ){
				j++;
			}

			prev_size = (int)out.size();
			for(int k=1; k<=(j-i); ++k){
				for(int idx=0; idx<prev_size; ++idx){
					vector<int> temp2 = out[idx];
					for(int q=0; q<k; ++q){
						temp2.push_back(nums[i]);
					}
					out.push_back(temp2);
				}
			}

			i=j;
		}

		return out;
    }
};
