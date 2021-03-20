/*
There is an integer array perm that is a permutation of the first n positive integers, where n is always odd.

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = perm[i] XOR perm[i + 1]. For example, if perm = [1,3,2], then encoded = [2,1].

Given the encoded array, return the original array perm. It is guaranteed that the answer exists and is unique.

 

Example 1:

Input: encoded = [3,1]
Output: [1,2,3]
Explanation: If perm = [1,2,3], then encoded = [1 XOR 2,2 XOR 3] = [3,1]
Example 2:

Input: encoded = [6,5,4,6]
Output: [2,4,1,5,3]
 

Constraints:

3 <= n < 105
n is odd.
encoded.length == n - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-xored-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
		vector<int> res;

		int tmp = 0;
		int tmp2 = 0;
		for (int i = 0; i < encoded.size(); ++i) {
			encoded[i] ^= tmp;
			tmp = encoded[i];
			tmp2 ^= tmp;
		}

		for (int i = 0; i < encoded.size() + 1; ++i) {
			tmp2 ^= i+1;
		}

		res.push_back(tmp2);
		for (int i = 0; i < encoded.size(); ++i) {
			res.push_back(tmp2^encoded[i]);
		}

		return res;
    }
};
