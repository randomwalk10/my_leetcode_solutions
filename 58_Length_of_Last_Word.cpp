/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/

#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
		int l1 = s.size(), l2;
		int res = 0;

		for (l2 = (int)s.size()-1; l2 >=0; --l2) {
			if(s[l2]==' '){
				if(l1>l2+1)
					return l1-1-l2;
				l1 = l2;
			}
		}
		if(l1>l2+1)
			res = l1 - 1 - l2;

		return res;
    }
};
