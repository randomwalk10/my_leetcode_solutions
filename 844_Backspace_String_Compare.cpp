/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/

#include <string>
using namespace std;

class Solution {
private:
	int findNextChar(string& input, int idx){
		if(idx<0) return idx;
		int cnt = 0;
		do{
			cnt += (input[idx]=='#')?-1:1;
			if(cnt>0) break;
			else --idx;
		}while(idx>=0);
		return idx;
	}
public:
    bool backspaceCompare(string S, string T) {
		int idx_s = S.size() - 1;
		int idx_t = T.size() - 1;
		while(true){
			idx_s = findNextChar(S, idx_s);
			idx_t = findNextChar(T, idx_t);
			if((idx_s>=0)&&(idx_t>=0)){
				if(S[idx_s]!=T[idx_t]) return false;
				--idx_s;
				--idx_t;
			}
			else if((idx_s<0)&&(idx_t<0)) break;
			else return false;
		}
		return true;
    }
};
