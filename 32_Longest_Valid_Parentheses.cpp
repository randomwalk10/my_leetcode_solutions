/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
		stack<char> char_s;
		stack<size_t> idx_s;
		int max_width = 0;
		for(size_t i=0; i<s.size(); ++i){
			if( (!char_s.empty())&&(char_s.top()=='(')&&(s[i]==')') ){
				char_s.pop();
				idx_s.pop();
			}
			else{
				char_s.push(s[i]);
				idx_s.push(i);
			}
		}
		if(idx_s.empty()) return (int)s.size();
		else{
			size_t cur_idx = s.size();
			while(!idx_s.empty()){
				int temp_width = (int)(cur_idx - idx_s.top() - 1);
				max_width = (temp_width>max_width) ? temp_width : max_width;
				cur_idx = idx_s.top();
				idx_s.pop();
			}
			int temp_width = (int)(cur_idx - 0);
			max_width = (temp_width>max_width) ? temp_width : max_width;
		}
		return max_width;
    }
};
