/*
Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times.

The Fibonacci numbers are defined as:

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 for n > 2.
It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.
 

Example 1:

Input: k = 7
Output: 2 
Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ... 
For k = 7 we can use 2 + 5 = 7.
Example 2:

Input: k = 10
Output: 2 
Explanation: For k = 10 we can use 2 + 8 = 10.
Example 3:

Input: k = 19
Output: 3 
Explanation: For k = 19 we can use 1 + 5 + 13 = 19.
 

Constraints:

1 <= k <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
		int res = 0;
		int a=1, b=1;
		vector<int> f(2, 1);

		while(a+b<=k){
			f.push_back(a+b);
			int temp = b;
			b = a + b;
			a = temp;
		}

		for (int i = f.size()-1; i >= 0; --i) {
			if(k>=f[i]){
				k -= f[i];
				++res;
			}
			if(k==0) break;
		}

		return res;
    }
};
