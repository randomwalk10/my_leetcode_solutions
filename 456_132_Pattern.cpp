/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.

Example 1:
Input: [1, 2, 3, 4]

Output: False

Explanation: There is no 132 pattern in the sequence.
Example 2:
Input: [3, 1, 4, 2]

Output: True

Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:
Input: [-1, 3, 2, 0]

Output: True

Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/132-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(N) in time and O(N) in space */
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s, l;
        int cur_min = INT_MAX;
        int prev_min = INT_MAX;

        for(int i=0; i<(int)nums.size(); ++i){
            cur_min = min(cur_min, nums[i]);
            while( (!s.empty())&&(s.top()<=nums[i]) ){
                s.pop(); l.pop();
            }
            if(!s.empty()){
                if(l.top()<nums[i]) return true;
            }
            s.push(nums[i]);
            l.push(prev_min);
            prev_min = cur_min;
        }

        return false;
    }
};
