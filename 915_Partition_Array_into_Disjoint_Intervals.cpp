/*
Given an array A, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

 

Example 1:

Input: [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
Example 2:

Input: [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]

Note:

2 <= A.length <= 30000
0 <= A[i] <= 10^6
It is guaranteed there is at least one way to partition A as described.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
		vector<int> dp_l(A.size(), 0), dp_r(A.size(), 0);
		dp_l[0] = A[0];
		dp_r[A.size()-1] = A[A.size()-1];

		for(int i=1; i<(int)A.size(); ++i){
			dp_l[i] = (dp_l[i-1]<A[i])?A[i]:dp_l[i-1]; 
		}

		for(int i=(int)A.size()-2; i>=0; --i){
			dp_r[i] = (dp_r[i+1]>A[i])?A[i]:dp_r[i+1];
		}

		int r=1;
		while( (r<(int)A.size()-1)&&(dp_l[r-1]>dp_r[r]) ){
			r++;
		}

		return r;
    }
};
