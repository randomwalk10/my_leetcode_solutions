#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
		int l, h;
		bool has_stock = false;
		int res = 0;
		for (int i = 0; i < (int)prices.size(); ++i) {
			if(i==0){
				l = prices[0];
				h = prices[0];
				continue;
			}
			if(has_stock){
				h = (prices[i]>h)?prices[i]:h;
				if(prices[i]+fee<=h){
					res += h - l - fee;
					has_stock = false;
					l = prices[i];
				}
			}
			else{
				l = (prices[i]<l)?prices[i]:l;
				if(prices[i]>=fee+l){
					has_stock = true;
					h = prices[i];
				}
			}
		}
		if(has_stock){
			res += h - l - fee;
		}
		return res;
    }
};
