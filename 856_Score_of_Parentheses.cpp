/*
Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2
Example 4:

Input: "(()(()))"
Output: 6
 

Note:

S is a balanced parentheses string, containing only ( and ).
2 <= S.length <= 50
*/
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {
		stack<int> scores;
		int score = 0;
		for(size_t i=0; i<S.length(); ++i){
			if(S[i]=='('){
				scores.push(score);
				score = 0;
			}
			else{
				score = (score) ? 2*score : 1;
				score += scores.top();
				scores.pop();
			}
		}

		return score;
    }
};
