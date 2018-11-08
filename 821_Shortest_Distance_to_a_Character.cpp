/*
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 

Note:

S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
		vector<int> res(S.length(), -1);
		int prev_idx = -1;
		
		//forward pass
		for(int i=0; i<(int)S.length(); ++i){
			if(S[i]==C){
				res[i] = 0;
				prev_idx = i;
			}
			else if(prev_idx>=0){
				res[i] = i - prev_idx;
			}
		}

		//backward pass
		prev_idx = -1;
		for(int i=(int)S.length()-1; i>=0; --i){
			if(S[i]==C){
				prev_idx = i;
			}
			else if(prev_idx>=0){
				if(res[i]>=0){
					res[i] = min(res[i], prev_idx-i);
				}
				else
					res[i] = prev_idx - i;
			}
		}

		return res;
    }
};
