/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water,
and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes"
(water inside that isn't connected to the water around the island). One cell is a square with side length 1.
The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
*/
#include <vector>
using namespace std;

//brutal force(slow)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
		int out=0;
		for(size_t row=0; row<grid.size(); row++){
			for(size_t col=0; col<grid[0].size(); col++){
				if(grid[row][col]){
					if( (0==row) || ( (row>0)&&(0==grid[row-1][col]) ) ) out++;
					if( (grid.size()==row+1) || ( (row+1<grid.size())&&(0==grid[row+1][col]) ) ) out++;
					if( (0==col) || ( (col>0)&&(0==grid[row][col-1]) ) ) out++;
					if( (grid[0].size()==col+1) || ( (col+1<grid[0].size())&&(0==grid[row][col+1]) ) ) out++;
				}
			}
		}
		return out;
    }
};

//breadth first search(slower)
/*
#include <queue>
#include <unordered_set>
#include <string>
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
		int out=0;
		unordered_set<string> visited;
		queue<vector<int>> q;

		for(size_t row=0; row<grid.size(); ++row){
			for(size_t col=0; col<grid[0].size(); ++col){
				if(grid[row][col]){
					vector<int> temp;
					temp.push_back(row);
					temp.push_back(col);
					q.push(temp);
					break;
				}
			}
		}

		while(false==q.empty()){
			//take new_pt from q
			vector<int> new_pt = q.front();
			q.pop();
			int row = new_pt[0];
			int col = new_pt[1];
			if(visited.end()!=visited.find(to_string(row)+"_"+to_string(col))) continue;

			//update out
			if( (0==row) || ( (row>0)&&(0==grid[row-1][col]) ) ) out++;
			if( ((int)grid.size()==row+1) || ( (row+1<(int)grid.size())&&(0==grid[row+1][col]) ) ) out++;
			if( (0==col) || ( (col>0)&&(0==grid[row][col-1]) ) ) out++;
			if( ((int)grid[0].size()==col+1) || ( (col+1<(int)grid[0].size())&&(0==grid[row][col+1]) ) ) out++;

			//update visited
			visited.insert( to_string(row)+"_"+to_string(col) );

			//find next pts
			if( (row>0)&&grid[row-1][col]&&(visited.end()==visited.find(to_string(row-1)+"_"+to_string(col))) ){
				vector<int> temp;
				temp.push_back(row-1);
				temp.push_back(col);
				q.push(temp);
			}
			if( (row+1<(int)grid.size())&&grid[row+1][col]&&(visited.end()==visited.find(to_string(row+1)+"_"+to_string(col))) ){
				vector<int> temp;
				temp.push_back(row+1);
				temp.push_back(col);
				q.push(temp);
			}
			if( (col>0)&&grid[row][col-1]&&(visited.end()==visited.find(to_string(row)+"_"+to_string(col-1))) ){
				vector<int> temp;
				temp.push_back(row);
				temp.push_back(col-1);
				q.push(temp);
			}
			if( (col+1<(int)grid[0].size())&&grid[row][col+1]&&(visited.end()==visited.find(to_string(row)+"_"+to_string(col+1))) ){
				vector<int> temp;
				temp.push_back(row);
				temp.push_back(col+1);
				q.push(temp);
			}
		}

		return out;
    }
};
*/
