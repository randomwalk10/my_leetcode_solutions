/*
Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:

Input: nums = [3, 4, 2]
Output: 6
Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.
Example 2:

Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation: 
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.
Note:

The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
		unordered_map<int, int> hist;//integer in nums array-> profits.
		int have = 0, have_not = 0;
		int res = 0;
		int l, r;

		//fill in hist
		for(int i=0; i<(int)nums.size(); ++i){
			hist[nums[i]] += nums[i];
		}

		//find max profit
		while(!hist.empty()){
			l = hist.begin()->first;
			r = l;
			//expand l and r
			bool exitFlag;
			do{
				exitFlag = true;
				if(hist.end()!=hist.find(l-1)){
					l--;
					exitFlag = false;
				}
				if(hist.end()!=hist.find(r+1)){
					r++;
					exitFlag = false;
				}
			}while(!exitFlag);
			//update profits
			//remove keys ranging in [l, r]
			for(int i=l; i<=r; ++i){
				//update profits
				unordered_map<int, int>::iterator iter = hist.find(i);
				if(l==i){
					have = res + iter->second;
					have_not = res;
				}
				else{
					have = have_not + iter->second;
					have_not = res;
				}
				res = max(have, have_not);
				//remove iter
				hist.erase(iter);
			}
		}

		return res;
    }
};
