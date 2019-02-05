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
using namespace std;

struct Node{
	Node(){};
	Node* child_[26] = {NULL};
	bool stop_ = false;
};

class Solution {
private:
	vector<vector<int>> diff_ = {{-1,0}, {1,0}, {0,-1}, {0,1}};
	void dfs(vector<vector<char>>& board, Node* p, \
			int r, int c, vector<string>& res, string& path){
		//check if valid or not
		if( (r<0)||(c<0)||(r>=(int)board.size())||(c>=(int)board[0].size()) ) return;
		if( board[r][c] == '#' ) return;//(r,c) is visited
		if( NULL==p->child_[board[r][c]-'a'] ) return;//not found in trie
		//update context
		path.push_back(board[r][c]);
		char temp_char = board[r][c];
		board[r][c] = '#';//visited
		//add to res if possible
		p = p->child_[temp_char-'a'];
		if(p->stop_){
			res.push_back(path);
			p->stop_ = false;//in case of duplicate
		}
		//search into neighbors
		for(int i=0; i<(int)diff_.size(); ++i){
			dfs(board, p, r+diff_[i][0], c+diff_[i][1], res, path);
		}
		//restore context
		board[r][c] = temp_char;
		path.pop_back();
		//return
		return;
	}
	void buildTrie(vector<string>& words, Node* head){
		for(int i=0; i<(int)words.size(); ++i){
			Node* p = head;
			for(int j=0; j<(int)words[i].size(); ++j){
				if(p->child_[words[i][j]-'a']==NULL)
					p->child_[words[i][j]-'a'] = new Node();
				p = p->child_[words[i][j]-'a'];
			}
			p->stop_ = true;
		}
	}
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> res;
		Node* head = new Node();
		string path;

		//build trie
		buildTrie(words, head);

		//dfs at each (r,c)
		for(int r=0; r<(int)board.size(); ++r){
			for(int c=0; c<(int)board[0].size(); ++c){
				dfs(board, head, r, c, res, path);
			}
		}

		return res;
    }
};
