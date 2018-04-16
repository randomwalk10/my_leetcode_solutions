/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
		int leftMostIdx = nums.size() - 1;
		for(int i = nums.size() - 1; i>=0; --i){
			if( (i+nums[i]) >= leftMostIdx ) leftMostIdx = i;
		}
		return leftMostIdx==0;
    }
};
