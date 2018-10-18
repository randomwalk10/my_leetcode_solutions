/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
		int l=0, r=0;
		vector<int> out(A.size(), 0);

		for(; r<(int)A.size(); ++r){
			if(!(A[r]&0x1)){
				if(r>l){
					int temp = out[l];
					out[l] = A[r];
					out[r] = temp;
				}
				else{
					out[r] = A[r];
				}
				l++;
			}
			else out[r] = A[r];
		}

		return out;
    }
};
