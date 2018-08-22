/*
Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.

 

Example 1:

Input: 1
Output: true
Example 2:

Input: 10
Output: false
Example 3:

Input: 16
Output: true
Example 4:

Input: 24
Output: false
Example 5:

Input: 46
Output: true
 

Note:

1 <= N <= 10^9
*/

class Solution {
public:
    bool reorderedPowerOf2(int N) {
		int* a = countDigits(N);
		bool isMatch;

		for(int i=0; i<31; ++i){
			int* b = countDigits(1<<i);

			isMatch = true;
			for(int j=0; j<10; ++j){
				if(a[j]!=b[j]){
					isMatch = false;
					break;
				}
			}

			delete[] b;
			if(isMatch) break;
		}

		delete[] a;
		return isMatch;
    }

	int* countDigits(int N){
		int* out = new int[10];
		for(int i=0; i<10; ++i) out[i]=0;
		while(N){
			out[N%10]++;
			N /= 10;
		}
		return out;
	}
};
