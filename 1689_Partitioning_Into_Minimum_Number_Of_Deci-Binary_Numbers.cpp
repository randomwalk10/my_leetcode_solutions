/*
A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

 

Example 1:

Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32
Example 2:

Input: n = "82734"
Output: 8
Example 3:

Input: n = "27346209830709182346"
Output: 9
 

Constraints:

1 <= n.length <= 105
n consists of only digits.
n does not contain any leading zeros and represents a positive integer.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
		int res = 0;
		for (size_t i = 0; i < n.size(); ++i) {
			res = (n[i]-'0'>res)?n[i]-'0':res;
		}
		return res;
    }
};
