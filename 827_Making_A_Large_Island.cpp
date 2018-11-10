/*
In a 2D grid of 0s and 1s, we change at most one 0 to a 1.

After, what is the size of the largest island? (An island is a 4-directionally connected group of 1s).

Example 1:

Input: [[1, 0], [0, 1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: [[1, 1], [1, 0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: [[1, 1], [1, 1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Notes:

1 <= grid.length = grid[0].length <= 50.
0 <= grid[i][j] <= 1.
*/
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
	vector<vector<int>> deltas = {{-1,0}, {1,0}, {0,-1}, {0,1}};
public:
    int largestIsland(vector<vector<int>>& grid) {
		vector<vector<int>> labels(grid.size(), vector<int>(grid[0].size(), -1));
		vector<int> island_sizes;
		int res = 0;
		stack<vector<int>> s;

		//fill in labels
		int idx = 0;
		for(int r=0; r<(int)grid.size(); ++r){
			for(int c=0; c<(int)grid[0].size(); ++c){
				if( (grid[r][c])&&(labels[r][c]<0) ){
					idx++;
					//dfs
					labels[r][c] = idx;
					int temp_size = 1;
					s.push({r, c});
					
					while(!s.empty()){
						int new_r = s.top()[0];
						int new_c = s.top()[1];
						s.pop();

						for(int i=0; i<(int)deltas.size(); ++i){
							int new_new_r = new_r + deltas[i][0];
							int new_new_c = new_c + deltas[i][1];
							if( (new_new_r>=0)&&(new_new_r<(int)grid.size())&& \
									(new_new_c>=0)&&(new_new_c<(int)grid[0].size())&& \
									(grid[new_new_r][new_new_c])&& \
									(labels[new_new_r][new_new_c]<0) ){
								temp_size++;
								labels[new_new_r][new_new_c] = idx;
								s.push({new_new_r, new_new_c});
							}
						}
					}
					//update island_sizes and res
					island_sizes.push_back(temp_size);
					res = max(res, temp_size);
				}
			}
		}

		//find maxmal island size if changing one 0 to 1
		for(int r=0; r<(int)grid.size(); ++r){
			for(int c=0; c<(int)grid[0].size(); ++c){
				if(labels[r][c]<0){
					vector<bool> neighbor_labels(island_sizes.size(), false);
					int temp_size = 1;
					for(int i=0; i<(int)deltas.size(); ++i){
						int new_r = r + deltas[i][0];
						int new_c = c + deltas[i][1];
						if( (new_r>=0)&&(new_r<(int)grid.size())&& \
								(new_c>=0)&&(new_c<(int)grid[0].size())&& \
								(labels[new_r][new_c]>0)&& \
								(false==neighbor_labels[labels[new_r][new_c]-1]) ){
								temp_size += island_sizes[labels[new_r][new_c]-1];
								neighbor_labels[labels[new_r][new_c]-1] = true;
						}
					}
					res = max(res, temp_size);
				}
			}
		}
		

		return res;
    }
};
