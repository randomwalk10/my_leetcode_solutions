/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/
#include <vector>
using namespace std;

class Solution {
private:
	void radix_sort(vector<int>& nums, vector<int>& out){
		out.assign(nums.begin(), nums.end());
		vector<int> temp;

		//sort
		for(int bit_offset=0; bit_offset<32; ++bit_offset){
			int bit_mask = (1<<bit_offset);
			int one_cnt=0;
			temp.assign(out.begin(), out.end());
			for(int i=0; i<(int)nums.size(); ++i){
				if(bit_mask&temp[i]) one_cnt++;
			}

			int l = 0;
			int r = (bit_offset<31) ? (int)nums.size()-one_cnt : one_cnt;
			for(int i=0; i<(int)nums.size(); ++i){
				if((bit_offset<31)&&(bit_mask&temp[i]))
					out[r++] = temp[i];
				else if(bit_offset<31)
					out[l++] = temp[i];
				else if(bit_mask&temp[i])
					out[l++] = temp[i];
				else
					out[r++] = temp[i];
			}
		}
	}
public:
    int longestConsecutive(vector<int>& nums) {
		if(nums.size()<2) return nums.size();
		vector<int> ranked;

		radix_sort(nums, ranked);

		int cnt = 1;
		int max_cnt = 1;
		for(int i=0; i<(int)ranked.size()-1; ++i){
			cnt = (ranked[i+1]==ranked[i]+1)?cnt+1: \
				  (ranked[i+1]==ranked[i])?cnt:1;
			max_cnt = (cnt>max_cnt)?cnt:max_cnt;
		}

		return max_cnt;
    }
};
