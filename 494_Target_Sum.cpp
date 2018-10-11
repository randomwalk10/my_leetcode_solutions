/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S.
Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:

The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/
#include <vector>
using namespace std;

//brutal force(dfs) slow
/*
class Solution {
private:
    void findTargetSumWays(vector<int>& nums, int S, int idx, int& cnt) {
		if(idx>=(int)nums.size()){
			if(0==S) cnt++;
			return;
		}

		//+
		findTargetSumWays(nums, S-nums[idx], idx+1, cnt);
		//-
		findTargetSumWays(nums, S+nums[idx], idx+1, cnt);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
		int cnt = 0;

		this->findTargetSumWays(nums, S, 0, cnt);

		return cnt;
    }
};
*/

//dynamic programing method
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
		if( (S>1000)||(S<-1000) ) return 0;
		vector<int> count_table(2001, 0);

		for(size_t i=0; i<nums.size(); ++i){
			if(0==i){
				count_table[nums[i]+1000] += 1;
				count_table[-nums[i]+1000] += 1;
			}
			else{
				vector<int> temp_table(2001, 0);
				for(int j=0; j<2001; ++j){
					if(count_table[j]){
						temp_table[j+nums[i]] += count_table[j];
						temp_table[j-nums[i]] += count_table[j];
					}
				}
				count_table = temp_table;
			}
		}

		return count_table[S+1000];
    }
};
