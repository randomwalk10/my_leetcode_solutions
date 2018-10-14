/*
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

Note: You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
 

Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
 

Example 3:

Input: amount = 10, coins = [10] 
Output: 1
*/
#include <vector>
#include <algorithm>
using namespace std;

/* exceeds time limitation(time complexity O(n**m), space complexity O(n), where n is amount, m is length of coins
class Solution {
private:
	void change(int amount, vector<int>& coins, int start, int& count){
		if(amount==0){
			count++;
			return;
		}
		for(int i=start; i<(int)coins.size(); ++i){
			if(amount<coins[i]) break;
			change(amount-coins[i], coins, i, count);
		}
		return;
	}
public:
    int change(int amount, vector<int>& coins) {
		int out = 0;
		sort(coins.begin(), coins.end());//ascending order

		this->change(amount, coins, 0, out);

		return out;
    }
};
*/

/* dp method, time complexity O(n*m) and space complexity O(n), where n is amount, m is length of coins */
class Solution {
public:
    int change(int amount, vector<int>& coins) {
		vector<int> dp(amount+1, 0);
		dp[0] = 1;

		for(int i=0; i<(int)coins.size(); ++i){
			for(int j=1; j<=amount; ++j){
				if(j>=coins[i])
					dp[j] += dp[j-coins[i]];
			}
		}

		return dp[amount];
    }
};
