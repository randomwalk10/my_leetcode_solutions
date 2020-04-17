/*
You have an integer and you can flip exactly one bit from a 0 to a 1. Write code to find the length of the longest sequence of 1s you could create.

Example 1:

Input: num = 1775(110111011112)
Output: 8
Example 2:

Input: num = 7(01112)
Output: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-bits-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int reverseBits(int num) {
		int res = 0;
		int prev_zero = -1;
		int prev_cnt = 0;

		for (int i = 0; i < 32; ++i) {
			if(num&(1<<i)){
				;
			}
			else{
				int cur_cnt = i - prev_zero - 1;
				res = ( (cur_cnt+prev_cnt+1)>res ) ? \
					  (cur_cnt+prev_cnt+1) : res;
				prev_zero = i;
				prev_cnt = cur_cnt;
			}
		}
		int cur_cnt = 32 - prev_zero - 1;
		res = ( (cur_cnt+prev_cnt+1)>res ) ? \
			  (cur_cnt+prev_cnt+1) : res;

		return res;
    }
};
