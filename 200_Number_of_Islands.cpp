/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/
#include <vector>
#include <queue>
using namespace std;

struct grid_index{
	int r;
	int c;
	grid_index(int row, int col): r(row), c(col){
	}
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
		int cnt = 0;
		vector<vector<char>> grid_backup = grid;
		//group all connected ones
		for(int r = 0; r < (int)grid_backup.size(); ++r){
			for(int c = 0; c < (int)grid_backup[0].size(); ++c){
				if(grid_backup[r][c]=='1'){
					cnt++;
					//visit all ones connected to [r][c] and set them to zero
					queue<grid_index> grid_queue;
					grid_queue.push(grid_index(r, c));
					while(!grid_queue.empty()){
						grid_index temp = grid_queue.front();
						grid_queue.pop();
						if(grid_backup[temp.r][temp.c]=='1'){
							grid_backup[temp.r][temp.c] = '0';
							vector<grid_index> neighbors = { \
								grid_index(temp.r-1, temp.c), \
									grid_index(temp.r+1, temp.c), \
									grid_index(temp.r, temp.c-1), \
									grid_index(temp.r, temp.c+1) };
							for(size_t i=0; i<neighbors.size(); ++i){
								if( \
										(0<=neighbors[i].r) && \
										((int)grid_backup.size()>neighbors[i].r) && \
										(0<=neighbors[i].c) && \
										((int)grid_backup[0].size()>neighbors[i].c) && \
										(grid_backup[neighbors[i].r][neighbors[i].c]=='1') \
								  ){
									grid_queue.push(neighbors[i]);
								}
							}
						}
					}
				}
			}
		}
		//return
		return cnt;
    }
};
