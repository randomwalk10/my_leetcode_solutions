/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

/* O(N) in time and O(N) in space */
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(int i=0; i<(int)tokens.size(); ++i){
            if(tokens[i][0]=='+'){
                int rhs = s.top(); s.pop();
                int lhs = s.top(); s.pop();
                s.push(lhs+rhs);
            }
            else if( (tokens[i].size()==1)&&(tokens[i][0]=='-') ){
                int rhs = s.top(); s.pop();
                int lhs = s.top(); s.pop();
                s.push(lhs-rhs);
            }
            else if(tokens[i][0]=='*'){
                int rhs = s.top(); s.pop();
                int lhs = s.top(); s.pop();
                s.push(lhs*rhs);
            }
            else if(tokens[i][0]=='/'){
                int rhs = s.top(); s.pop();
                int lhs = s.top(); s.pop();
                s.push(lhs/rhs);
            }
            else{
                int temp = 0;
                bool is_pos = true;
                for(int j=0; j<(int)tokens[i].size(); ++j){
                    if(tokens[i][j]=='-') is_pos = false;
                    else{
                        temp = temp*10 + tokens[i][j] - '0';
                    }
                }

                if(is_pos) s.push(temp);
                else s.push(-temp);
            }
        }

        return s.top();
    }
};
