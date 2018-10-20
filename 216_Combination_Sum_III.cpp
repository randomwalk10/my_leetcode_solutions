/*
Find all possible combinations of k numbers that add up to a number n,
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/
#include <vector>
using namespace std;

class Solution {
private:
	void combinationSum3(int k, int n, int start, vector<int> path,
			vector<vector<int>>& res){
		if( (0==k)&&(0==n) ){
			res.push_back(path);
			return;
		}
		else if( (0>=k)||(0>=n) ) return;

		for(int i=start; i<=10-k; ++i){
			path.push_back(i);
			combinationSum3(k-1, n-i, i+1, path, res);
			path.pop_back();
		}
		
		return;
	}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> out;
		vector<int> path;

		combinationSum3(k, n, 1, path, out);

		return out;
    }
};
