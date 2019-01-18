/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
#include <vector>
using namespace std;

class Solution {
private:
	void combine(const int &n, const int& k, int idx, \
			vector<int>& path, \
			vector<vector<int>>& res){
		//check condition
		if((int)path.size()==k){//one combination is found
			res.push_back(path);
			return;
		}
		else if( (n+1-idx+(int)path.size())<k ) return;//no combination possible
		//transverse
		for(int i=idx; i<=n; ++i){
			path.push_back(i);
			combine(n, k, i+1, path, res);
			path.pop_back();
		}
		//return
		return;
	}
public:
    vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> path;
		combine(n, k, 1, path, res);
		return res;
    }
};
