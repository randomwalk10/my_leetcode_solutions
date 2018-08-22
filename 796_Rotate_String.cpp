/*
We are given two strings, A and B.

A shift on A consists of taking string A and moving the leftmost character to the rightmost position.
For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if
A can become B after some number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
Note:

A and B will have length at most 100.
*/
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
		if(A.empty() && B.empty()) return true;
		else if(A.size()!=B.size()) return false;

		for(size_t i=0; i<A.size(); ++i){
			if(A[i]==B[0]){
				bool isMatch = true;
				for(size_t j=1; j<A.size(); ++j){
					if(A[(i+j)%A.size()]!=B[j]){
						isMatch = false;
						break;
					}
				}
				if(isMatch) return true;
			}
		}

		return false;
    }
};
