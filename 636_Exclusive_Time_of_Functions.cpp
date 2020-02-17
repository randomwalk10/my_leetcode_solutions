/*
On a single threaded CPU, we execute some functions.  Each function has a unique id between 0 and N-1.

We store logs in timestamp order that describe when a function is entered or exited.

Each log is a string with this format: "{function_id}:{"start" | "end"}:{timestamp}".  For example, "0:start:3" means the function with id 0 started at the beginning of timestamp 3.  "1:end:2" means the function with id 1 ended at the end of timestamp 2.

A function's exclusive time is the number of units of time spent in this function.  Note that this does not include any recursive calls to child functions.

The CPU is single threaded which means that only one function is being executed at a given time unit.

Return the exclusive time of each function, sorted by their function id.


Input:
n = 2
logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
Output: [3, 4]
Explanation:
Function 0 starts at the beginning of time 0, then it executes 2 units of time and reaches the end of time 1.
Now function 1 starts at the beginning of time 2, executes 4 units of time and ends at time 5.
Function 0 is running again at the beginning of time 6, and also ends at the end of time 6, thus executing for 1 unit of time.
So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.
 

Note:

1 <= n <= 100
Two functions won't start or end at the same time.
Functions will always log when they exit.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/exclusive-time-of-functions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(N) in time and O(N) in space */

#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> s_id, s_start;
        vector<int> res(n, 0);
        for(int i=0; i<(int)logs.size(); ++i){
            int j =0;
            int id = 0;
            int time_stamp = 0;
            bool is_start = true;
            while(':'!=logs[i][j]){
                id = id*10 + logs[i][j] - '0';
                ++j;
            }

            is_start = logs[i][++j]=='s';
            while(':'!=logs[i][j]){
                ++j;
            }
            ++j;

            while(j<(int)logs[i].size()){
                time_stamp = time_stamp*10 + logs[i][j] - '0';
                ++j;
            }

            if(is_start){
                s_id.push(id);
                s_start.push(time_stamp);
            }
            else{
                s_id.pop();
                int start_time = s_start.top(); s_start.pop();
                res[id] += time_stamp + 1 - start_time;

                if(!s_id.empty()){
                    int prev_id = s_id.top();
                    res[prev_id] -= time_stamp + 1 - start_time;
                }
            }
        }
        return res;
    }
};
