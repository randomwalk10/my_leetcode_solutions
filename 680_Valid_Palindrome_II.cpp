/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/
#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
		int l = 0;
		int r = s.size() - 1;
		int count = 0;
		int back_l = -1;
		int back_r = -1;

		while(r>l){
			if(s[l]!=s[r]){
				count++;
				if(count>1){
					if(-1!=back_l){
						l = back_l;
						r = back_r;
						back_l = -1;
						back_r = -1;
						count--;
					}
					else return false;
				}
				else{
					if( (s[l+1]==s[r]) && (s[l]==s[r-1]) ){
						back_l = l+1;
						back_r = r;
						r--;
					}
					else if(s[l+1]==s[r]) l++;
					else if(s[l]==s[r-1]) r--;
					else return false;
				}
			}
			else{
				l++;
				r--;
			}
		}

		return true;
    }
};
