/*
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.

*/

#include <vector>
using namespace std;

class Solution {
private:
	void lexicalOrder(int n, int prev, vector<int>& res){
		int start = (prev)?0:1;
		for(int i=start; i<10; ++i){
			int temp = prev + i;
			if(temp>n) break;
			else{
				res.push_back(temp);
				lexicalOrder(n, temp*10, res);
			}
		}
	}
public:
    vector<int> lexicalOrder(int n) {
		vector<int> res;
		lexicalOrder(n, 0, res); // dfs
		return res;
    }
};
