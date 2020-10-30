/*
A robot on an infinite grid starts at point (0, 0) and faces north.  The robot can receive one of three possible types of commands:

-2: turn left 90 degrees
-1: turn right 90 degrees
1 <= x <= 9: move forward x units
Some of the grid squares are obstacles. 

The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])

If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route.)

Return the square of the maximum Euclidean distance that the robot will be from the origin.

 

Example 1:

Input: commands = [4,-1,3], obstacles = []
Output: 25
Explanation: robot will go to (3, 4)
Example 2:

Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
Output: 65
Explanation: robot will be stuck at (1, 4) before turning left and going to (1, 8)
 

Note:

0 <= commands.length <= 10000
0 <= obstacles.length <= 10000
-30000 <= obstacle[i][0] <= 30000
-30000 <= obstacle[i][1] <= 30000
The answer is guaranteed to be less than 2 ^ 31.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/walking-robot-simulation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		const long long min_limit = -30000;
		unordered_set<long long> obs;
		int angle = 90;
		int res = 0;
		int x = 0, y = 0;

		for (size_t i = 0; i < obstacles.size(); ++i) {
			obs.insert(obstacles[i][0]-min_limit+(obstacles[i][1]-min_limit)*(2*min_limit+1));
		}

		for (size_t i = 0; i < commands.size(); ++i) {
			if(commands[i]==-2){
				angle += 90; 
				angle = angle % 360;
			}
			else if(commands[i]==-1){
				angle -= 90;
				if(angle<0) angle += 360;
			}
			else{
				int tmp_x = x, tmp_y = y;
				for (int t = 1; t <= commands[i]; ++t) {
					if(angle==0){
						++tmp_x;
					}
					else if(angle==90){
						++tmp_y;
					}
					else if(angle==180){
						--tmp_x;
					}
					else if(angle==270){
						--tmp_y;
					}
					if(obs.find(tmp_x-min_limit+(tmp_y-min_limit)*(2*min_limit+1))!=obs.end()) break;
					else{
						x = tmp_x; y = tmp_y;
					}
				}
				res = max(res, x*x+y*y);
			}
		}

		return res;
    }
};
