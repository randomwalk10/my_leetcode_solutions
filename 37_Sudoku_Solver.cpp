/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	bool reduceSudoku(vector<vector<string>>& board_s){
		for(size_t r=0; r<board_s.size(); ++r){
			for(size_t c=0; c<board_s[0].size(); ++c){
				if(1==board_s[r][c].size()){
					//row reduction
					for(size_t c1=0; c1<board_s[0].size(); ++c1){
						if(c1==c) continue;
						size_t match_pos = \
										   board_s[r][c1].find(board_s[r][c]);
						if(string::npos != match_pos){
							board_s[r][c1].erase(match_pos, 1);
							if(board_s[r][c1].empty()) return false;
						}
					}
					//col reduction
					for(size_t r1=0; r1<board_s.size(); ++r1){
						if(r1==r) continue;
						size_t match_pos = \
										   board_s[r1][c].find(board_s[r][c]);
						if(string::npos != match_pos){
							board_s[r1][c].erase(match_pos, 1);
							if(board_s[r1][c].empty()) return false;
						}
					}
					//3x3 box reduction
					for(size_t r1=(r/3)*3; r1<(r/3+1)*3; ++r1){
						for(size_t c1=(c/3)*3; c1<(c/3+1)*3; ++c1){
							if( (r1==r) || (c1==c) ) continue;
							size_t match_pos = \
											   board_s[r1][c1].find(board_s[r][c]);
							if(string::npos != match_pos){
								board_s[r1][c1].erase(match_pos, 1);
								if(board_s[r1][c1].empty()) return false;
							}
						}
					}
				}
			}
		}
		return true;
	}

	bool solveSudoku(vector<vector<string>>& board_s){
		//perform reduction
		if(false == reduceSudoku(board_s)) return false;
		//branch out
		//find the cell with min len of letters and this len is >1
		//if not return true
		{
			int min_len = 1;
			size_t target_r = 0, target_c = 0;
			for(size_t r=0; r<board_s.size(); ++r){
				for(size_t c=0; c<board_s[0].size(); ++c){
					if( (board_s[r][c].size()>1) && \
							( (min_len==1) || \
							  ((int)board_s[r][c].size()<min_len) ) ){
							min_len = board_s[r][c].size();
							target_r = r;
							target_c = c;
					}
				}
			}
			if(1==min_len) return true;
			//iterate over letters of this cell
			//if true, return true
			string temp = board_s[target_r][target_c];
			vector<vector<string>> board_s_backup = board_s;
			for(int i=0; i<min_len; ++i){
				board_s[target_r][target_c] = temp.substr(i, 1);
				if(solveSudoku(board_s)) return true;
				board_s = board_s_backup;
			}
		}
		//return
		return false;
	}
public:
    void solveSudoku(vector<vector<char>>& board) {
		vector<vector<string>> board_s;
		//preprocess board
		for(size_t r=0; r<board.size(); ++r){
			vector<string> temp;
			board_s.push_back(temp);
			for(size_t c=0; c<board[0].size(); ++c){
				if(board[r][c]=='.')
					board_s[r].push_back("123456789");
				else
					board_s[r].push_back(string(1, board[r][c]));
			}
		}
		//iteratively perform reduction and branching
		solveSudoku(board_s);
		//postprocessing board
		for(size_t r=0; r<board.size(); ++r){
			for(size_t c=0; c<board[0].size(); ++c){
				board[r][c] = board_s[r][c][0];
			}
		}
    }
};
