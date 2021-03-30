/*
Given an array of positive integers arr (not necessarily distinct), return the lexicographically largest permutation that is smaller than arr, that can be made with exactly one swap (A swap exchanges the positions of two numbers arr[i] and arr[j]). If it cannot be done, then return the same array.

 

Example 1:

Input: arr = [3,2,1]
Output: [3,1,2]
Explanation: Swapping 2 and 1.
Example 2:

Input: arr = [1,1,5]
Output: [1,1,5]
Explanation: This is already the smallest permutation.
Example 3:

Input: arr = [1,9,4,6,7]
Output: [1,7,4,6,9]
Explanation: Swapping 9 and 7.
Example 4:

Input: arr = [3,1,1,3]
Output: [1,3,1,3]
Explanation: Swapping 1 and 3.
 

Constraints:

1 <= arr.length <= 104
1 <= arr[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/previous-permutation-with-one-swap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
		map<int,vector<int>, greater<int>> val2pos;
		for (int i = arr.size()-1; i >= 0; --i) {
			auto iter = val2pos.upper_bound(arr[i]);
			if(iter!=val2pos.end()){
				int j = iter->second.back();
				arr[i] ^= arr[j];
				arr[j] ^= arr[i];
				arr[i] ^= arr[j];
				break;
			}
			else{
				val2pos[arr[i]].push_back(i);
			}
		}
		return arr;
    }
};
