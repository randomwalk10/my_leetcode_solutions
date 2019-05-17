/*
We have an array A of non-negative integers.

For every (contiguous) subarray B = [A[i], A[i+1], ..., A[j]] (with i <= j), we take the bitwise OR of all the elements in B, obtaining a result A[i] | A[i+1] | ... | A[j].

Return the number of possible results.  (Results that occur more than once are only counted once in the final answer.)

 

Example 1:

Input: [0]
Output: 1
Explanation: 
There is only one possible result: 0.
Example 2:

Input: [1,1,2]
Output: 3
Explanation: 
The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.
Example 3:

Input: [1,2,4]
Output: 6
Explanation: 
The possible results are 1, 2, 3, 4, 6, and 7.
 

Note:

1 <= A.length <= 50000
0 <= A[i] <= 10^9
*/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
		unordered_set<int> res; // store all results
		unordered_set<int> cur; // store bitwise or of subarrays from any j to i where j <= i
		unordered_set<int> cur_prev; // store bitwise or of subarrays from any j to i-1 where j <= i-1

		// O(30*n)
		// the reason is that cur and cur_prev are of size up to 30,
		// because e.g, the bitwise or of subarray [A[0], A[1]] has all the 1's that [A[1]] has and may
		// have 1's at the bit positions where [A[1]] is zero. # bit increasing
		for(int i=0; i<(int)A.size(); ++i){
			cur = {A[i]};
			for(int tmp : cur_prev) cur.insert(tmp|A[i]); // create cur
			for(int tmp : cur) res.insert(tmp); // update res
			cur_prev = cur; // update cur_prev
		}

		return res.size();
    }
};
