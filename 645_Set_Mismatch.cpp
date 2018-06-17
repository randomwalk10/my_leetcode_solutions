/*
The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in
the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number
occurs twice and then find the number that is missing. Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.
*/
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
		int n = nums.size();
		int sum = 0;
		vector<int> out;
		//detect the duplicated number
		for(size_t i=0; i<nums.size(); ++i){
			if(nums[abs(nums[i])-1] < 0) out.push_back(abs(nums[i]));
			else nums[abs(nums[i])-1] *= -1;
			sum += abs(nums[i]);
		}

		//find the missing number by substraction
		out.push_back( n*(n+1)/2 - sum + out[0] );
		
		//return
		return out;
    }
};
