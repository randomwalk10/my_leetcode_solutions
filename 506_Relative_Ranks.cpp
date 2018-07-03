/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//time complexity O(nlogn); lambda function in cpp: )
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
		vector<string> out(nums.size());
		vector<int> rank;

		//initialize rank
		for(int i=0; i<(int)nums.size(); ++i){
			rank.push_back(i);
		}

		//rank in descending order
		sort(rank.begin(), rank.end(), [&](int a, int b){return nums[a]>nums[b];});
		
		//fill in out
		for(int i=0; i<(int)nums.size(); ++i){
			if(0==i) out[rank[i]] = "Gold Medal";
			else if(1==i) out[rank[i]] = "Silver Medal";
			else if(2==i) out[rank[i]] = "Bronze Medal";
			else out[rank[i]] = to_string(i+1);
		}

		//return
		return out;
    }
};
