/*
In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the ith domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

 

Example 1:


Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
 

Constraints:

2 <= A.length == B.length <= 2 * 104
1 <= A[i], B[i] <= 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-domino-rotations-for-equal-row
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
		int res = -1;
		int tmp;

		tmp = 0;
		for (int i = 1; i < A.size(); ++i) {
			if(A[i]==A[0]) continue;
			else if(B[i]==A[0]) ++tmp;
			else{
				tmp = -1;
				break;
			}
		}
		if(tmp>=0) res = (res>=0)?min(res, tmp):tmp;

		tmp = 0;
		for (int i = 1; i < A.size(); ++i) {
			if(B[i]==B[0]) continue;
			else if(A[i]==B[0]) ++tmp;
			else{
				tmp = -1;
				break;
			}
		}
		if(tmp>=0) res = (res>=0)?min(res, tmp):tmp;

		tmp = 1;
		for (int i = 1; i < A.size(); ++i) {
			if(B[i]==A[0]) continue;
			else if(A[i]==A[0]) ++tmp;
			else{
				tmp = -1;
				break;
			}
		}
		if(tmp>=0) res = (res>=0)?min(res, tmp):tmp;

		tmp = 1;
		for (int i = 1; i < A.size(); ++i) {
			if(A[i]==B[0]) continue;
			else if(B[i]==B[0]) ++tmp;
			else{
				tmp = -1;
				break;
			}
		}
		if(tmp>=0) res = (res>=0)?min(res, tmp):tmp;

		return res;
    }
};
