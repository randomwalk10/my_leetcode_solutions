/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
*/
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
	vector<vector<int>> offsets = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		stack<vector<int>> s;
		int res = 0;

		for(int r=0; r<(int)grid.size(); ++r){
			for(int c=0; c<(int)grid[0].size(); ++c){
				if( grid[r][c] && (!visited[r][c]) ){
					//dfs
					visited[r][c] = true;
					s.push({r, c});
					int temp = 0;
					while(!s.empty()){
						int r2 = s.top()[0];
						int c2 = s.top()[1];
						s.pop();
						temp++;
						for(size_t i=0; i<offsets.size(); ++i){
							int new_r = r2 + offsets[i][0];
							int new_c = c2 + offsets[i][1];
							if( (new_r>=0)&&(new_c>=0)&&(new_r<(int)grid.size())&& \
									(new_c<(int)grid[0].size())&&(grid[new_r][new_c])&& \
									(!visited[new_r][new_c]) ){
								visited[new_r][new_c] = true;
								s.push({new_r, new_c});
							}
						}
					}
					//update res
					res = max(res, temp);
				}
			}
		}

		return res;
    }
};
