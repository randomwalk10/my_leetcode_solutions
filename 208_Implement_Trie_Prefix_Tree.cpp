/*
 Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/
#include <string>
using namespace std;

struct Node{
	Node(){
		stop_ = false;
	};
	Node* child_[26] = {NULL};
	bool stop_;
};


class Trie {
private:
	Node* head_;
public:
    /** Initialize your data structure here. */
    Trie() {
		head_ = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
		Node* temp = head_;
		for(int i=0; i<(int)word.size(); ++i){
			if(NULL == temp->child_[word[i]-'a'])
				temp->child_[word[i]-'a'] = new Node();
			temp = temp->child_[word[i]-'a'];
		}
		temp->stop_ = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
		Node* temp = head_;
		for(int i=0; i<(int)word.size(); ++i){
			if(NULL == temp->child_[word[i]-'a'])
				return false;
			temp = temp->child_[word[i]-'a'];
		}
		return temp->stop_;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		Node* temp = head_;
		for(int i=0; i<(int)prefix.size(); ++i){
			if(NULL == temp->child_[prefix[i]-'a'])
				return false;
			temp = temp->child_[prefix[i]-'a'];
		}
		return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
