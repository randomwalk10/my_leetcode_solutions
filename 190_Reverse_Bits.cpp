/*
Reverse bits of a given 32 bits unsigned integer.

Example:

Input: 43261596
Output: 964176192
Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
             return 964176192 represented in binary as 00111001011110000010100101000000.
Follow up:
If this function is called many times, how would you optimize it?

*/
#define uint32_t unsigned int

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		uint32_t output = 0;

		for(int i=0; i<32; ++i){
			output = (output<<1) + (n&0x1);
			n = (n>>1);
		}

		return output;
    }
};
