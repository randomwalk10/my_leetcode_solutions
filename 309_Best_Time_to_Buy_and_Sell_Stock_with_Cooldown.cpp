/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int* cash = new int[n];
		int* stock = new int[n];
		int* cooldown = new int[n];

		int i=1;
		cash[0] = 0;
		stock[0] = 0;
		cooldown[0] = 0;
		while(i<n){
			cash[i] = (cooldown[i-1]>cash[i-1]) ? \
					  cooldown[i-1] : cash[i-1];
			stock[i] = ((stock[i-1]+prices[i]-prices[i-1])>cash[i-1]) ? \
					   (stock[i-1]+prices[i]-prices[i-1]) : cash[i-1];
			cooldown[i] = stock[i-1]+prices[i]-prices[i-1];

			i++;
		}
        
		return (cash[n-1]>cooldown[n-1]) ? \
			cash[n-1] : cooldown[n-1];
    }
};
