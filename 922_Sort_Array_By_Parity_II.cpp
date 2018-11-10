/*
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
 

Note:

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
		vector<int> res(A.begin(), A.end());
		vector<int> prev_odd;
		vector<int> prev_even;

		for(int i=0; i<(int)A.size(); ++i){
			if( (i%2)&&(res[i]%2==0) ){
				if(!prev_odd.empty()){
					swap(res[prev_odd.back()], res[i]);
					prev_odd.pop_back();
				}
				else prev_even.push_back(i);
			}
			else if( (i%2==0)&&(res[i]%2) ){
				if(!prev_even.empty()){
					swap(res[prev_even.back()], res[i]);
					prev_even.pop_back();
				}
				else prev_odd.push_back(i);
			}
		}

		return res;
    }
};
