/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
		if(nums.empty()) return vector<int>();
		// fill in vector of availables
		vector<bool> availables(nums.size(), false);
		for(int i=0; i<(int)nums.size(); ++i){
			availables[nums[i]-1] = true;
		}
		// find missing numbers
		vector<int> res;
		for(int i=0; i<(int)nums.size(); ++i){
			if(!availables[i]) res.push_back(i+1);
		}
		// return
		return res;
    }
};
