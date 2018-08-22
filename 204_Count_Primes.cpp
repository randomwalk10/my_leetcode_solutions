/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

class Solution {
public:
    int countPrimes(int n) {
		int *isPrime = new int[n];
		int cnt = 0;

		for(int i=0; i<n; ++i) isPrime[i] = 1;

		for(int i=2; i<n; ++i){
			if(isPrime[i-1]){
				cnt++;
				int j=2;
				while(i*j<n){
					isPrime[i*j-1]=0;
					j++;
				}
			}
		}

		delete[] isPrime;
		return cnt;
    }
};
