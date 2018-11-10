/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
		string res;
		int start = 0;

		while(start<(int)s.length()){
			if( (s[start]>='0')&&(s[start]<='9') ){
				//determine n
				int n = 0;
				while(s[start]!='['){
					n = n*10 + (s[start]-'0');
					start++;
				}
				//find the range of brackets
				int prev_start = start + 1;
				int cnt = 1;
				while(cnt){
					start++;
					if(s[start]==']') cnt--;
					else if(s[start]=='[') cnt++;
				}
				//replicate string in the brackets
				string temp = decodeString(s.substr(prev_start, start-prev_start));
				for(int i=0; i<n; ++i){
					res.append(temp);
				}
				//update start
				start++;
			}
			else{
				res.append(1, s[start++]);
			}
		}

		return res;
    }
};
