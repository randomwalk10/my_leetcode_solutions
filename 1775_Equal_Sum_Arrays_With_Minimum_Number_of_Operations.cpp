/*
You are given two arrays of integers nums1 and nums2, possibly of different lengths. The values in the arrays are between 1 and 6, inclusive.

In one operation, you can change any integer's value in any of the arrays to any value between 1 and 6, inclusive.

Return the minimum number of operations required to make the sum of values in nums1 equal to the sum of values in nums2. Return -1​​​​​ if it is not possible to make the sum of the two arrays equal.

 

Example 1:

Input: nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
Output: 3
Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed.
- Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2].
- Change nums1[5] to 1. nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2].
- Change nums1[2] to 2. nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2].
Example 2:

Input: nums1 = [1,1,1,1,1,1,1], nums2 = [6]
Output: -1
Explanation: There is no way to decrease the sum of nums1 or to increase the sum of nums2 to make them equal.
Example 3:

Input: nums1 = [6,6], nums2 = [1]
Output: 3
Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed. 
- Change nums1[0] to 2. nums1 = [2,6], nums2 = [1].
- Change nums1[1] to 2. nums1 = [2,2], nums2 = [1].
- Change nums2[0] to 4. nums1 = [2,2], nums2 = [4].
 

Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[i] <= 6


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/equal-sum-arrays-with-minimum-number-of-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
		if(nums1.size()>6*nums2.size()) return -1;
		else if(6*nums1.size()<nums2.size()) return -1;
		int res = 0;

		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < nums1.size(); ++i) {
			sum1 += nums1[i];
		}
		for (int i = 0; i < nums2.size(); ++i) {
			sum2 += nums2[i];
		}
		if(sum1==sum2) return 0;

		vector<int> freq(6, 0);
		for (int i = 0; i < nums1.size(); ++i) {
			if(sum1>sum2) ++freq[nums1[i]-1];
			else ++freq[6-nums1[i]];
		}
		for (int i = 0; i < nums2.size(); ++i) {
			if(sum2>sum1) ++freq[nums2[i]-1];
			else ++freq[6-nums2[i]];
		}

		int diff = max(sum1, sum2) - min(sum1, sum2);
		for (int i = 6; i > 1; --i) {
			int tmp = diff/(i-1);
			int r = diff%(i-1);
			if(tmp<freq[i-1]){
				res += tmp;
				if(r>0) ++res;
				return res;
			}
			else if(tmp==freq[i-1]){
				diff -= tmp*(i-1);
				res += tmp;
				if(r==0) return res;
			}
			else{
				diff -= freq[i-1]*(i-1);
				res += freq[i-1];
			}
		}

		return -1;
    }
};
