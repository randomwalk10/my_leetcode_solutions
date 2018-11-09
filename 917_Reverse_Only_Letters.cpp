/*
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S doesn't contain \ or "
*/
#include <string>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
		if(S.size()<2) return S;
		int l = 0;
		int r = (int)S.size()-1;

		while(l<r){
			while( (l<(int)S.size()) && ((S[l]<'a')||(S[l]>'z')) && \
					((S[l]<'A')||(S[l]>'Z')) )
				l++;
			while( (r>=0) && ((S[r]<'a')||(S[r]>'z')) && \
					((S[r]<'A')||(S[r]>'Z')) )
				r--;
			if(l<r) swap(S[l++], S[r--]);
		}

		return S;
    }
};
