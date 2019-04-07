/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
		// calculate partition sum
		int partition_sum = 0;
		for(int i=0; i<(int)nums.size(); ++i){
			partition_sum += nums[i];
		}
		if(partition_sum%2) return false;
		partition_sum = partition_sum>>1;
		// search for partition based on dynamic programming
		vector<int> sums(partition_sum+1, false);
		sums[0] = true;
		for(int i=0; i<(int)nums.size(); ++i){
			for(int j=partition_sum; j>0; --j){
				int temp = j - nums[i];
				if(temp<0) break;
				sums[j] |= sums[temp];
				if( (j==partition_sum)&&sums[j] ) return true;
			}
		}
		// return
		return sums[partition_sum];
    }
};
