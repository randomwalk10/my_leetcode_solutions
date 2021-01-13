/*
You are given an integer array nums. You can choose exactly one index (0-indexed) and remove the element. Notice that the index of the elements may change after the removal.

For example, if nums = [6,1,7,4,1]:

Choosing to remove index 1 results in nums = [6,7,4,1].
Choosing to remove index 2 results in nums = [6,1,4,1].
Choosing to remove index 4 results in nums = [6,1,7,4].
An array is fair if the sum of the odd-indexed values equals the sum of the even-indexed values.

Return the number of indices that you could choose such that after the removal, nums is fair.

 

Example 1:

Input: nums = [2,1,6,4]
Output: 1
Explanation:
Remove index 0: [1,6,4] -> Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
Remove index 1: [2,6,4] -> Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
Remove index 2: [2,1,4] -> Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
Remove index 3: [2,1,6] -> Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
There is 1 index that you can remove to make nums fair.
Example 2:

Input: nums = [1,1,1]
Output: 3
Explanation: You can remove any index and the remaining array is fair.
Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: You cannot make a fair array after removing any index.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ways-to-make-a-fair-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int total_odd_sum = 0;
        int total_even_sum = 0;
        int cur_odd_sum = 0;
        int cur_even_sum = 0;
        int res = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if(i%2) total_odd_sum += nums[i];
            else total_even_sum += nums[i];
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if(i%2) cur_odd_sum += nums[i];
            else cur_even_sum += nums[i];

            int odds1 = (i%2)?cur_odd_sum-nums[i]:cur_odd_sum;
            int evens1 = (i%2)?cur_even_sum:cur_even_sum-nums[i];
            int odds2 = total_odd_sum-cur_odd_sum;
            int evens2 = total_even_sum-cur_even_sum; 
            if(odds1+evens2==evens1+odds2) ++res;
        }
        
        return res;
    }
};