/*
Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], for each query i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). Return an array containing the result for the given queries.
 

Example 1:

Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
Example 2:

Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xor-queries-of-a-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
		vector<int> res;
		vector<vector<int>> s(arr.size(), vector<int>(32, 0));

		for (int i = 0; i < (int)arr.size(); ++i) {
			for (int j = 0; j < 32; ++j) {
				if(arr[i]&(1<<j)){
					if(i==0) s[i][j] = 1;
					else s[i][j] = s[i-1][j] + 1;
				}
				else{
					if(i==0) s[i][j] = 0;
					else s[i][j] = s[i-1][j];
				}
			}
		}

		for (int i = 0; i < (int)queries.size(); ++i) {
			int l = queries[i][0];
			int r = queries[i][1];
			int temp = 0;
			for (int j = 0; j < 32; ++j) {
				int mask = 1<<j;
				int one_cnt = s[r][j] - s[l][j];
				if(arr[l]&mask) ++one_cnt;
				if(one_cnt%2) temp |= mask;
			}
			res.push_back(temp);
		}

		return res;
    }
};
