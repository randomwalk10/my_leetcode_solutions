/*
There are n people that are split into some unknown number of groups. Each person is labeled with a unique ID from 0 to n - 1.

You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in. For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.

Return a list of groups such that each person i is in a group of size groupSizes[i].

Each person should appear in exactly one group, and every person must be in a group. If there are multiple answers, return any of them. It is guaranteed that there will be at least one valid solution for the given input.

 

Example 1:

Input: groupSizes = [3,3,3,3,3,1,3]
Output: [[5],[0,1,2],[3,4,6]]
Explanation: 
The first group is [5]. The size is 1, and groupSizes[5] = 1.
The second group is [0,1,2]. The size is 3, and groupSizes[0] = groupSizes[1] = groupSizes[2] = 3.
The third group is [3,4,6]. The size is 3, and groupSizes[3] = groupSizes[4] = groupSizes[6] = 3.
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
Example 2:

Input: groupSizes = [2,1,3,3,3,2]
Output: [[1],[0,5],[2,3,4]]
 

Constraints:

groupSizes.length == n
1 <= n <= 500
1 <= groupSizes[i] <= n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-the-people-given-the-group-size-they-belong-to
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		vector<vector<int>> res;
		unordered_map<int, vector<int>> size2groups;

		for (int i = 0; i < (int)groupSizes.size(); ++i) {
			int size = groupSizes[i];
			unordered_map<int, vector<int>>::iterator iter = size2groups.find(size);
			if(iter==size2groups.end()){
				res.push_back({i});
				size2groups[size] = {(int)res.size()-1};
			}
			else{
				if(res[iter->second[iter->second.size()-1]].size()<size){
					res[iter->second[iter->second.size()-1]].push_back(i);
				}
				else{
					res.push_back({i});
					iter->second.push_back(res.size()-1);
				}
			}
		}

		return res;
    }
};
