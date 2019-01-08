/*
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
 

Note:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.
*/
#include <string>
using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
		if(A.size()!=B.size()) return false;
		int cnt=0;
		char A_swap, B_swap;
		int f[26] = {0};
		bool anyDuplicate = false;

		for(int i=0; i<(int)A.size(); ++i){
			//find differences
			if(A[i]!=B[i]){
				if(cnt==0){
					A_swap = A[i];
					B_swap = B[i];
					cnt++;
				}
				else if(cnt==1){
					if( (A_swap==B[i])&&(B_swap==A[i]) ){
						cnt++;
					}
					else return false;
				}
				else return false;
			}
			//find duplicates
			f[A[i]-'a']++;
			if(f[A[i]-'a']>1) anyDuplicate = true;
		}

		return (cnt==2)||((cnt==0)&&anyDuplicate);
    }
};
