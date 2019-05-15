/*
We have two integer sequences A and B of the same non-zero length.

We are allowed to swap elements A[i] and B[i].  Note that both elements are in the same index position in their respective sequences.

At the end of some number of swaps, A and B are both strictly increasing.  (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... < A[A.length - 1].)

Given A and B, return the minimum number of swaps to make both sequences strictly increasing.  It is guaranteed that the given input always makes it possible.

Example:
Input: A = [1,3,5,4], B = [1,2,3,7]
Output: 1
Explanation: 
Swap A[3] and B[3].  Then the sequences are:
A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
which are both strictly increasing.
Note:

A, B are arrays with the same length, and that length will be in the range [1, 1000].
A[i], B[i] are integer values in the range [0, 2000].
*/
#include <vector>
using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
		if(A.size()<2) return 0;
		int cnt1 = 0; // count of swaps with no swap at the last index
		int cnt2 = 1; // count of swaps with swap at the last index

		// dynamic programming
		// iterate through A and B
		for(int i=1; i<(int)A.size(); ++i){ // start at index 1
			int tmp1 = INT_MAX, tmp2 = INT_MAX, tmp3 = INT_MAX, tmp4 = INT_MAX;
			if( (A[i]>A[i-1])&&(B[i]>B[i-1]) ){
				tmp1 = cnt1;
				tmp3 = (cnt2==INT_MAX)?cnt2:cnt2+1;
			}
			if( (A[i]>B[i-1])&&(B[i]>A[i-1]) ){
				tmp2 = cnt2;
				tmp4 = (cnt1==INT_MAX)?cnt1:cnt1+1;
			}
			cnt1 = min(tmp1, tmp2);
			cnt2 = min(tmp3, tmp4);
		}

		// return
		return min(cnt1, cnt2);
    }
};
