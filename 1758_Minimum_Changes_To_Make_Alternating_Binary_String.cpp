/*
You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.

 

Example 1:

Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.
Example 2:

Input: s = "10"
Output: 0
Explanation: s is already alternating.
Example 3:

Input: s = "1111"
Output: 2
Explanation: You need two operations to reach "0101" or "1010".
 

Constraints:

1 <= s.length <= 104
s[i] is either '0' or '1'.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-changes-to-make-alternating-binary-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
		int r_p = 0, r_n = 0;
		bool one = true;

		for (int i = 0; i < (int)s.size(); ++i) {
			if(s[i]=='1'){
				if(one){
					++r_n;
				}
				else{
					++r_p;
				}
			}
			else{
				if(one){
					++r_p;
				}
				else{
					++r_n;
				}
			}
			one = !one;
		}

		return min(r_p, r_n);
    }
};
