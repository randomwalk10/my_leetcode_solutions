/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example:

Input: [5,7]
Output: 4
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
		int output = 0;

		for(int i=0; i<31; ++i){
			int bit_mask = 1<<i;
			if( (m&bit_mask) && \
					(n&bit_mask) && \
					((n-m)<bit_mask) ) 
				output |= bit_mask;
		}

		return output;
    }
};
