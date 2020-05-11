/*
Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.

 

Example 1:

Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
Example 2:

Input: arr = [1,1,1,1,1]
Output: 10
Example 3:

Input: arr = [2,3]
Output: 0
Example 4:

Input: arr = [1,3,5,7,9]
Output: 3
Example 5:

Input: arr = [7,11,12,9,5,2,7,17,22]
Output: 8
 

Constraints:

1 <= arr.length <= 300
1 <= arr[i] <= 10^8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(N) in time and O(N) in space */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
		int res = 0;
		vector<int> temp1(arr.size(), 0);
		unordered_map<int, int> temp2; // accumulative index sums
		unordered_map<int, int> temp3; // occurences

		int i;
		int prev_val = 0;
		temp2[0] = -1;
		temp3[0] = 1;
		for (i = 0; i < (int)arr.size(); ++i) {
			int val = prev_val ^ arr[i];
			int cnt = temp3[val]*(i-1) - temp2[val];
			prev_val = val;
			temp2[val] += i;
			temp3[val] += 1;
			res += cnt;
		}

		return res;
    }
};
