/*
 Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only hold
integers within the 32-bit signed integer range. For the purpose
of this problem, assume that your function returns 0 when the
reversed integer overflows.
*/
#include "limits.h"
class Solution {
public:
    int reverse(int x) {
		int temp_in = x;
		int temp_out = 0;
		while(temp_in){
			int reserved = temp_out;
			temp_out = 10 * temp_out + temp_in % 10;
			if( (temp_out - temp_in % 10) / 10 != reserved ) return 0;
			temp_in /= 10;
		}
		return temp_out;
    }
};
