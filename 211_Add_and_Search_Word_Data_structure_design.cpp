/*
 Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/
#include <string>
#include <unordered_map>
using namespace std;

struct Node{
	Node(){
	};
	unordered_map<char, Node*> child_;
	bool stop_ = false;
};

class WordDictionary {
private:
	Node* head_;
	bool search(string& word, int pos, Node* temp){
		//exit condition
		if(pos==(int)word.size())
			return temp->stop_;
		//'.'
		if(word[pos]=='.'){
			if(temp->child_.empty()) return false;
			for(unordered_map<char, Node*>::iterator iter = \
					temp->child_.begin(); iter != temp->child_.end(); \
					++iter){
				if(search(word, pos+1, iter->second)) return true;
			}
			return false;
		}
		//a-z
		if(temp->child_.end()==temp->child_.find(word[pos])) return false;
		return search(word, pos+1, temp->child_[word[pos]]);
	}
public:
    /** Initialize your data structure here. */
    WordDictionary() {
		head_ = new Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
		if(word.empty()) return;
		Node* temp = head_;
		for(int i=0; i<(int)word.size(); ++i){
			if(temp->child_.end()==temp->child_.find(word[i]))
				temp->child_[word[i]] = new Node();
			temp = temp->child_[word[i]];
		}
		temp->stop_ = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
		return search(word, 0, head_);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
