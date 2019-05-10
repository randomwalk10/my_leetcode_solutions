/*
In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

 

Example 1:

Input: [[0,1],[1,0]]
Output: 1
Example 2:

Input: [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 

Note:

1 <= A.length = A[0].length <= 100
A[i][j] == 0 or A[i][j] == 1
*/

#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
private:
	const vector<pair<int, int>> diffs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
public:
    int shortestBridge(vector<vector<int>>& A) {
		int res = 1;
		int rows = A.size();
		int cols = A[0].size();
		queue<pair<int, int>> q1, q2;

		for(int r = 0; r < rows; ++r){
			for(int c = 0; c < cols; ++c){
				if(A[r][c]){
					// bfs through the first island
					// find all zero neighbors (mark as -1)
					// mark 2d points in the first island as 2
					q1.push(pair<int, int>(r, c));
					A[r][c] = 2;
					while(!q1.empty()){
						// get new node from q1
						pair<int, int> new_node = q1.front();
						q1.pop();
						// find its neighbors (1's)
						for(int i=0; i<(int)diffs.size(); ++i){
							pair<int, int> new_new_node = pair<int, int>( \
									new_node.first+diffs[i].first, \
									new_node.second+diffs[i].second );
							if( (new_new_node.first>=0)&&(new_new_node.first<rows)&& \
									(new_new_node.second>=0)&&(new_new_node.second<cols) ){
								if(1==A[new_new_node.first][new_new_node.second]){ // ones
									A[new_new_node.first][new_new_node.second] = 2;
									q1.push(new_new_node);
								}
								else if(0==A[new_new_node.first][new_new_node.second]){ // zeros
									A[new_new_node.first][new_new_node.second] = -1;
									q2.push(new_new_node);
								}
							}
						}
					}
					// bfs through all zeros, starting from the found zero neighbors
					// mark visited zero points as negative numbers
					// exit when the second island is found
					while(true){
						// get new node from q2
						pair<int, int> new_node = q2.front();
						q2.pop();
						// find its neighbors (0's)
						for(int i=0; i<(int)diffs.size(); ++i){
							pair<int, int> new_new_node = pair<int, int>( \
									new_node.first+diffs[i].first, \
									new_node.second+diffs[i].second );
							if( (new_new_node.first>=0)&&(new_new_node.first<rows)&& \
									(new_new_node.second>=0)&&(new_new_node.second<cols) ){
								if(0==A[new_new_node.first][new_new_node.second]){ // zeros
									A[new_new_node.first][new_new_node.second] \
										= -1 + A[new_node.first][new_node.second];
									q2.push(new_new_node);
								}
								else if(1==A[new_new_node.first][new_new_node.second]){ // ones
									// return
									res = -A[new_node.first][new_node.second];
									return res;
								}
							}
						}
					}
				}
			}
		}

		// return
		return res;
    }
};
