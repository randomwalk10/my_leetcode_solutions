/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> brackets_stack;
		for(size_t i=0; i<s.size(); ++i){
			if( (s[i]=='(') || (s[i]=='{') || (s[i]=='[') ) brackets_stack.push(s[i]);
			else if(brackets_stack.size()>0){
				if( (brackets_stack.top()=='(') && (s[i]==')') );
				else if( (brackets_stack.top()=='{') && (s[i]=='}') );
				else if( (brackets_stack.top()=='[') && (s[i]==']') );
				else return false;
				brackets_stack.pop();
			}
			else return false;
		}
		return (brackets_stack.size()) ? false : true;
    }
};
