/*
 Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example:

Input: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

Output: ["eat","oath"]
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
private:
	vector<vector<int>> diff_ = {{-1,0}, {1,0}, {0,-1}, {0,1}};
	bool findWordInBoardAtLoc(vector<vector<char>>& board, string& word, \
			int idx, int r, int c, vector<vector<bool>>& is_visited){
		if(idx==(int)word.size()) return true;
		else if( (0>r)||(r>=(int)board.size())|| \
				(0>c)||(c>=(int)board[0].size())|| \
				is_visited[r][c]||(word[idx]!=board[r][c]) )
				return false;
		bool res = false;
		//set is_visited[r][c]
		is_visited[r][c] = true;
		//dfs
		for(int i=0; i<(int)diff_.size(); ++i){
			int new_r = r + diff_[i][0];
			int new_c = c + diff_[i][1];
			res = findWordInBoardAtLoc(board, word, idx+1, new_r, new_c, is_visited);
			if(res) break;
		}
		//restore is_visited[r][c]
		is_visited[r][c] = false;
		//return
		return res;
	}
	bool findWordInBoard(vector<vector<char>>& board, string& word, \
			vector<vector<bool>>& is_visited){
		if(word.empty()) return false;
		//find matching char to start with
		//then perform dfs to match the word
		//return true if matching is found
		for(int r=0; r<(int)board.size(); ++r){
			for(int c=0; c<(int)board[0].size(); ++c){
				if( findWordInBoardAtLoc(board, word, 0, r, c, is_visited) ){
					return true;
				}
			}
		}

		//return
		return false;
	}
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		unordered_set<string> res_set;
		vector<string> res;
		vector<vector<bool>> is_visited(board.size(), vector<bool>(board[0].size(), false));

		for(int i=0; i<(int)words.size(); ++i){
			//dfs for each word
			//append to res if true
			if(findWordInBoard(board, words[i], is_visited))
				res_set.insert(words[i]);
		}

		for(unordered_set<string>::iterator iter = res_set.begin(); \
				iter != res_set.end(); ++iter){
			res.push_back(*iter);
		}

		return res;
    }
};
