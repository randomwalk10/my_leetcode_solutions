/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Example 1:

Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
Example 2:

Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
Note: Length of the array will not exceed 10,000.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
		if(nums.empty()) return 0;
		int out=1;
		int temp;

		for(int i=0; i<(int)nums.size(); ++i){
			if( (0<i)&&(nums[i]>nums[i-1]) ){
				temp++;
			}
			else{
				temp=1;
			}
			out=(out<temp)?temp:out;
		}

		return out;
    }
};
