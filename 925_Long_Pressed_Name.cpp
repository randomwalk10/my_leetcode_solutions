/*
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true
Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.
 

Note:

name.length <= 1000
typed.length <= 1000
The characters of name and typed are lowercase letters.
*/
#include <string>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
		if(name.size()>typed.size()) return false;
		int i=0, i2=0;
		int n=name.size(), k=typed.size();
		char cur;

		while(i<n){
			if(i2>=k) return false;
			cur = name[i];
			int temp = i;
			while( (i<n)&&(cur==name[i]) ){
				i++;
			}

			int cnt = i-temp;
			while( (i2<k)&&(cur==typed[i2]) ){
				i2++;
				cnt--;
			}
			if(cnt>0){
				return false;
			}
		}

		return true;
    }
};
