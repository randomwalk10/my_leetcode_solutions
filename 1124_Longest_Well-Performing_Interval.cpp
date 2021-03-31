/*
We are given hours, a list of the number of hours worked per day for a given employee.

A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.

 

Example 1:

Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
 

Constraints:

1 <= hours.length <= 10000
0 <= hours[i] <= 16

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-well-performing-interval
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
		stack<int> s;
		vector<int> presum(hours.size()+1, 0);
		int res = 0;
		for (int i = 0; i < hours.size(); ++i) {
			presum[i+1] = presum[i] + ((hours[i]>8)?1:-1);
		}
		for (int i = 0; i < presum.size(); ++i) {
			if((s.empty()==false)&&(presum[s.top()]<=presum[i])){
				continue;
			}
			else s.push(i);
		}
		for (int i = presum.size()-1; i >= 0; --i) {
			while((s.empty()==false)&&(presum[s.top()]<presum[i])){
				res = max(res, i - s.top());
				s.pop();
			}
			if(s.empty()) break;
		}
		return res;
    }
};
