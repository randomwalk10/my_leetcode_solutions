/*
Given a string representing arbitrarily nested ternary expressions, calculate the result of the expression. You can always assume that the given expression is valid and only consists of digits 0-9, ?, :, T and F (T and F represent True and False respectively).

Note:

The length of the given string is ≤ 10000.
Each number will contain only one digit.
The conditional expressions group right-to-left (as usual in most languages).
The condition will always be either T or F. That is, the condition will never be a digit.
The result of the expression will always evaluate to either a digit 0-9, T or F.
Example 1:

Input: "T?2:3"

Output: "2"

Explanation: If true, then result is 2; otherwise result is 3.
Example 2:

Input: "F?1:T?4:5"

Output: "4"

Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(F ? 1 : (T ? 4 : 5))"                   "(F ? 1 : (T ? 4 : 5))"
          -> "(F ? 1 : 4)"                 or       -> "(T ? 4 : 5)"
          -> "4"                                    -> "4"
Example 3:

Input: "T?T?F:5:3"

Output: "F"

Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) : 3)"
          -> "(T ? F : 3)"                 or       -> "(T ? F : 5)"
          -> "F"                                    -> "F"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ternary-expression-parser
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(N) in time and O(N) in space */

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string parseTernary(string expression) {
		stack<int> s, s_l, s_r;
		stack<char> s_res;
		string res;
		// push stack
		for(int i=0; i<(int)expression.size(); ++i){
			if(expression[i]=='?')
				s.push(i);
		}
		// pop stack
		while(!s.empty()){
			int idx = s.top(); s.pop();
			if(expression[idx-1]=='T'){
				if(s_res.empty()){
					res = expression[idx+1];
					s_l.push(idx-1);
					s_r.push(idx+3);
					s_res.push(expression[idx+1]);
				}
				else{
					// left
					int temp_r;
					if(idx+1==s_l.top()){
						res = s_res.top();
						temp_r = s_r.top() + 2;
						s_l.pop(); s_res.pop(); s_r.pop();
					}
					else{
						res = expression[idx+1];
						temp_r = idx + 3;
					}
					// right
					if( (!s_res.empty())&&(temp_r==s_l.top()) ){
						temp_r = s_r.top();
						s_l.pop(); s_res.pop(); s_r.pop();
					}
					// update
					s_res.push(res[0]);
					s_l.push(idx-1);
					s_r.push(temp_r);
				}
			}
			else{
				if(s_res.empty()){
					res = expression[idx+3];
					s_l.push(idx-1);
					s_r.push(idx+3);
					s_res.push(expression[idx+3]);
				}
				else{
					// left
					int temp_r;
					if(idx+1==s_l.top()){
						temp_r = s_r.top() + 2;
						s_l.pop(); s_res.pop(); s_r.pop();
					}
					else{
						temp_r = idx + 3;
					}
					// right
					if( (!s_res.empty())&&(temp_r==s_l.top()) ){
						res = s_res.top();
						temp_r = s_r.top();
						s_l.pop(); s_res.pop(); s_r.pop();
					}
					else{
						res = expression[temp_r];
					}
					// update
					s_res.push(res[0]);
					s_l.push(idx-1);
					s_r.push(temp_r);
				}
			}
		}
		// return
		return res;
    }
};
