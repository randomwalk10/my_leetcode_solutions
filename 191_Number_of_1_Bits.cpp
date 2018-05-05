/*
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example :

Input: 11
Output: 3
Explanation: the 32-bit integer 11 has binary representation 00000000000000000000000000001011 .
*/
#define uint32_t unsigned int

class Solution {
public:
    int hammingWeight(uint32_t n) {
		int cnt = 0;

		while(n){
			cnt += (n&0x1);
			n >>= 1;
		}

		return cnt;
    }
};
