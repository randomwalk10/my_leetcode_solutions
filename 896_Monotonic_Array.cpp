/*
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.

 

Example 1:

Input: [1,2,2,3]
Output: true
Example 2:

Input: [6,5,4,4]
Output: true
Example 3:

Input: [1,3,2]
Output: false
Example 4:

Input: [1,2,4,5]
Output: true
Example 5:

Input: [1,1,1]
Output: true
 

Note:

1 <= A.length <= 50000
-100000 <= A[i] <= 100000
*/
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
		if(2>A.size()) return true;
		int trend = 0;//1 for increasing only; -1 for decresing only; 0 for undetermined
		
		for(size_t i=0; i<A.size()-1; ++i){
			if( (0<trend)&&(A[i]>A[i+1]) ) return false;
			if( (0>trend)&&(A[i]<A[i+1]) ) return false;
			if( (0==trend)&&(A[i]<A[i+1]) ) trend = 1;
			else if( (0==trend)&&(A[i]>A[i+1]) ) trend = -1;
		}

		return true;
    }
};
