/*
A super ugly number is a positive integer whose prime factors are in the array primes.

Given an integer n and an array of integers primes, return the nth super ugly number.

The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

 

Example 1:

Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
Example 2:

Input: n = 1, primes = [2,3,5]
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
 

Constraints:

1 <= n <= 106
1 <= primes.length <= 100
2 <= primes[i] <= 1000
primes[i] is guaranteed to be a prime number.
All the values of primes are unique and sorted in ascending order.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/super-ugly-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <queue>
using namespace std;

struct Compare{
	bool operator() (pair<int, int>& lhs, pair<int, int>& rhs){
		return lhs.first > rhs.first; // first ugly number, second prime number index
	}
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> dp(n, 1);
		vector<int> indice(primes.size(), 0);
		priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;

		for (int i = 0; i < primes.size(); ++i) {
			q.push({primes[i], i});
		}

		int i = 1;
		while(i<n){
			{
				pair<int, int> tmp = q.top();
				q.pop();
				dp[i] = tmp.first;
				tmp.first = dp[++indice[tmp.second]] * primes[tmp.second];
				q.push(tmp);
			}
			while(dp[i]==q.top().first){
				pair<int, int> tmp = q.top();
				q.pop();
				tmp.first = dp[++indice[tmp.second]] * primes[tmp.second];
				q.push(tmp);
			}
			++i;
		}

		return dp[n-1];
    }
};
