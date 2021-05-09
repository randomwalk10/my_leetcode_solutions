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
    int nthUglyNumber(int n) {
		vector<int> dp(n, 1);
		vector<int> primes = {2,3,5};
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
