/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-subarray-minimums
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
		stack<int> sl_le, sr_l;
		vector<int> left(arr.size(), 0);
		vector<int> right(arr.size(), 0);
		long long res = 0;

		for (int i = 0; i < arr.size(); ++i) {
			while((sl_le.empty()==false)&&(arr[sl_le.top()]>=arr[i])){
				sl_le.pop();
			}
			if(sl_le.empty()) left[i] = i+1;
			else left[i] = i-sl_le.top();
			sl_le.push(i);
		}

		for (int i = arr.size()-1; i >= 0; --i) {
			while((sr_l.empty()==false)&&(arr[sr_l.top()]>arr[i])){
				sr_l.pop();
			}
			if(sr_l.empty()) right[i] = arr.size()-i;
			else right[i] = sr_l.top() - i;
			sr_l.push(i);
		}

		for (int i = 0; i < arr.size(); ++i) {
			res += (long long)left[i]*right[i]*arr[i];
		}

		return res % (1000000000+7);
    }
};
