/*
You are given coins of different denominations and a total amount of
money amount. Write a function to compute the fewest number of coins
that you need to make up that amount. If that amount of money cannot
be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		if(amount==0) return 0;
		vector<int> dp_step(1+amount);
		int min_val = coins[0];

		for(size_t i=0; i<coins.size(); ++i)
			min_val = (coins[i] < min_val) ? coins[i] : min_val;
		if(min_val>amount) return -1;

		for(int i=1; i<=amount; ++i){
			dp_step[i] = -1;
			for(size_t j=0; j<coins.size(); ++j){
				if(i==coins[j]){
					dp_step[i] = 1;
					break;
				}
				else if( (i>coins[j]) && \
						(dp_step[i-coins[j]]!=-1) ){
					int temp = 1 + dp_step[i-coins[j]];
					if(dp_step[i]==-1){
						dp_step[i] = temp;
					}
					else{
						dp_step[i] = (temp<dp_step[i]) ? \
									 temp : dp_step[i];
					}
				}
			}
		}

		return dp_step[amount];
    }
};
