/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-four
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
		unsigned int n = num;
		int i=0;
		while(n){
			if(n&0x1){
				if(i%2) return false;
				else return n==1;
			}
			n >>= 1;
			++i;
		}
		return false;
    }
};
