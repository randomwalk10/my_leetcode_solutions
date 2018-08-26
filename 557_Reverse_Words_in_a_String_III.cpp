/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
		string out;

		int i=0;
		stack<char> reversed;

		while(i<(int)s.size()){
			while( (i<(int)s.size()) && (s[i]!=' ') ){
				reversed.push(s[i]);
				i++;
			}
			while(reversed.empty()==false){
				out.push_back(reversed.top());
				reversed.pop();
			}

			if(i<(int)s.size()) out.push_back(s[i]);
			i++;
		}

		return out;
    }
};
