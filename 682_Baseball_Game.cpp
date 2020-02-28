/*
You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

Integer (one round's score): Directly represents the number of points you get in this round.
"+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
"D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
"C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
Each round's operation is permanent and could have an impact on the round before and the round after.

You need to return the sum of the points you could get in all the rounds.

Example 1:
Input: ["5","2","C","D","+"]
Output: 30
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get 2 points. The sum is: 7.
Operation 1: The round 2's data was invalid. The sum is: 5.  
Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
Example 2:
Input: ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get -2 points. The sum is: 3.
Round 3: You could get 4 points. The sum is: 7.
Operation 1: The round 3's data is invalid. The sum is: 3.  
Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
Round 5: You could get 9 points. The sum is: 8.
Round 6: You could get -4 + 9 = 5 points. The sum is 13.
Round 7: You could get 9 + 5 = 14 points. The sum is 27.
Note:
The size of the input list will be between 1 and 1000.
Every integer represented in the list will be between -30000 and 30000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/baseball-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(N) in time and O(N) in space */

#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        int res = 0;

        for(int i=0; i<(int)ops.size(); ++i){
            if(ops[i][0]=='+'){
                int prev1 = s.top(); s.pop();
                int prev2 = s.top(); s.pop();
                s.push(prev2);
                s.push(prev1);
                s.push(prev1+prev2);
            }
            else if(ops[i][0]=='D'){
                s.push(2*s.top());
            }
            else if(ops[i][0]=='C'){
                s.pop();
            }
            else{
                int temp = 0;
                bool is_pos = true;
                for(int j=0; j<(int)ops[i].size(); ++j){
                    if(ops[i][j]=='-') is_pos = false;
                    else temp = temp*10 + ops[i][j] - '0';
                }
                if(is_pos) s.push(temp);
                else s.push(-temp);
            }
        }

        while(!s.empty()){
            res += s.top(); s.pop();
        }

        return res;
    }
};
