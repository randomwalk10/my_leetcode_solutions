/*
Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.


Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we want to return an integer, the decimal part will be truncated.
*/

class Solution {
public:
    int mySqrt(int x) {
		if(0==x) return 0;
		int l=1, r=x;
		int temp = l + (r-l)/2;
		while((r-l)>1){
			if(temp>x/temp) r = temp;
			else l = temp;
			temp = l + (r-l)/2;
		}
		return l;
    }
};
