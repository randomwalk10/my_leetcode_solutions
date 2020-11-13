/*
Given an array arr.  You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

 

Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has size greater than half of the size of the old array.
Example 2:

Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.
Example 3:

Input: arr = [1,9]
Output: 1
Example 4:

Input: arr = [1000,1000,3,7]
Output: 1
Example 5:

Input: arr = [1,2,3,4,5,6,7,8,9,10]
Output: 5
 

Constraints:

1 <= arr.length <= 10^5
arr.length is even.
1 <= arr[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reduce-array-size-to-the-half
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
		int res = 0;
		vector<int> counts;
		unordered_map<int, int> val2idx;
		for (size_t i = 0; i < arr.size(); ++i) {
			unordered_map<int, int>::iterator iter = val2idx.find(arr[i]);
			if (iter==val2idx.end()) {
				val2idx[arr[i]] = counts.size();
				counts.push_back(1);
			}
			else{
				counts[iter->second] += 1;
			}
		}
		std::sort(counts.begin(), counts.end(), [](int l, int r){return l>r;});
		int N = arr.size()>>1;
		int C = 0;
		for (size_t i = 0; i < counts.size(); ++i) {
			C += counts[i];
			++res;
			if(C>=N) break;
		}
		return res;
    }
};
