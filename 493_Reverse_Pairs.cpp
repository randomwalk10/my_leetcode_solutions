/*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:

The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	int search(int idx, vector<int>& bits){
		int res = 0;
		while(idx<(int)bits.size()){ // if idx==(int)bits.size() then idx is invalid according to index()
			res += bits[idx];
			idx += idx & (-idx);
		}
		return res;
	}
	void insert(int idx, vector<int>& bits){
		while(idx>0){//initial idx is in [1, bits.size()-1]
			++bits[idx];
			idx -= idx & (-idx);
		}
	}
	int index(long long input, vector<int>& copy){
		int l = 0; // the right most idx where copy[l] < input 
		int r = copy.size() - 1; // the left most idx where copy[r] >= input

		// binary search
		if((long long)copy[l] >= input) return 0;
		else if((long long)copy[r] < input) return r+1;
		while(l+1<r){
			int m = l + ((r-l)>>1);
			if((long long)copy[m]>=input) r = m;
			else l = m; 
		}

		// return
		return r;
	}
public:
    int reversePairs(vector<int>& nums) {
		if(nums.size()<2) return 0;
		int res = 0;
		int len = nums.size();
		vector<int> copy(nums);
		vector<int> bits(len+1, 0);

		// sort the copy of nums
		std::sort(copy.begin(), copy.end());

		// iterate backwards through nums
		for(int i=0; i<len; ++i){
			res += search(index(2*(long long)nums[i]+1, copy)+1, bits);
			insert(index(nums[i], copy)+1, bits);
		}

		// return
		return res;
    }
};
