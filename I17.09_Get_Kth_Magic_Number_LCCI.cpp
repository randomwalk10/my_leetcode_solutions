/*
Design an algorithm to find the kth number such that the only prime factors are 3, 5, and 7. Note that 3, 5, and 7 do not have to be factors, but it should not have any other prime factors. For example, the first several multiples would be (in order) 1, 3, 5, 7, 9, 15, 21.

Example 1:

Input: k = 5

Output: 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/get-kth-magic-number-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
		vector<int> f = {3,5,7};
		priority_queue<long long, vector<long long>, greater<long long>> s;
		s.push(1);
		int res = -1;

		while(k>0){
			while(res==s.top()) s.pop();
			res = s.top();
			s.pop();
			for (int i = 0; i < f.size(); ++i) {
				s.push((long long)f[i]*res);
			}
			--k;
		}

		return res;
    }
};
