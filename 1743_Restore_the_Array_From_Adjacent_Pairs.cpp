/*
There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of them.

 

Example 1:

Input: adjacentPairs = [[2,1],[3,4],[3,2]]
Output: [1,2,3,4]
Explanation: This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.
Example 2:

Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
Output: [-2,4,1,-3]
Explanation: There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.
Example 3:

Input: adjacentPairs = [[100000,-100000]]
Output: [100000,-100000]
 

Constraints:

nums.length == n
adjacentPairs.length == n - 1
adjacentPairs[i].length == 2
2 <= n <= 105
-105 <= nums[i], ui, vi <= 105
There exists some nums that has adjacentPairs as its pairs.


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
		unordered_map<int, vector<int>> m;
		vector<int> res;

		for(auto p: adjacentPairs){
			m[p[0]].push_back(p[1]);
			m[p[1]].push_back(p[0]);
		}

		int first_element;
		int new_element;
		for(auto iter=m.begin(); iter!=m.end(); ++iter){
			if(iter->second.size()==1){
				first_element = iter->first;
				new_element = iter->second[0];
				break;
			}
		}

		res.push_back(first_element);
		while(true){
			res.push_back(new_element);
			if(m[new_element].size()==1){
				break;
			}
			else if(m[new_element][0]==first_element){
				first_element = new_element;
				new_element = m[new_element][1];
			}
			else{
				first_element = new_element;
				new_element = m[new_element][0];
			}
		}

		return res;
    }
};
