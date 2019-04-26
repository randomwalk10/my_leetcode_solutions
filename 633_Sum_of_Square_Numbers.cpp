/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
 

Example 2:

Input: 3
Output: False
*/
#include <math.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
		int l = 0, r = sqrt(c);

		while(l<=r){
			int tmp = c - r*r - l*l;
			if(tmp==0) return true;
			else if(tmp<0) --r;
			else ++l;
		}

		return false;
    }
};
