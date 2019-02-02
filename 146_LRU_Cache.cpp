/*
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/
#include <unordered_map>
using namespace std;

struct Node{
	Node *left_, *right_;
	int key_, val_;
	Node(): left_(NULL), right_(NULL), key_(0), val_(0){
	};
	Node(int k, int v): left_(NULL), right_(NULL), key_(k), val_(v){
	};
};

class DoubleLinedList{
	private:
		Node *head_, *tail_;
	public:
		DoubleLinedList(){
			head_=NULL;
			tail_=NULL;
		}
		~DoubleLinedList(){
			while(head_){
				Node* temp = head_;
				head_ = head_->right_;
				delete temp;
			}
		}
		Node* addNewNode(int k, int v){
			Node* temp = new Node(k, v);
			if(head_){
				temp->right_ = head_;
				head_->left_ = temp;
				head_ = temp;
			}
			else{
				head_ = temp;
				tail_ = temp;
			}
			return head_;
		}
		int popTail(){
			if(NULL==tail_) return -1;

			int res = tail_->key_;

			if(tail_->left_){
				tail_ = tail_->left_;
				delete tail_->right_;
				tail_->right_ = NULL;
			}
			else{
				delete tail_;
				head_ = NULL;
				tail_ = NULL;
			}

			return res;
		}
		void moveToHead(Node* target){
			if(head_==target) return;
			//delete
			if(target->right_){
				target->left_->right_ = target->right_;
				target->right_->left_ = target->left_;
			}
			else{
				tail_ = target->left_;
				tail_->right_ = NULL;
			}
			//add to head
			target->left_ = NULL;
			target->right_ = head_;
			head_->left_ = target;
			head_ = target;
		}
};

class LRUCache {
private:
	unordered_map<int, Node*> map_;
	int capacity_;
	DoubleLinedList deque_;
public:
    LRUCache(int capacity) {
		capacity_ = capacity;
    }

    int get(int key) {
		//find key
		unordered_map<int, Node*>::iterator iter = map_.find(key);
		if(map_.end()==iter) return -1;

		//update deque_ and return val
		deque_.moveToHead(iter->second);
		return iter->second->val_;
    }

    void put(int key, int value) {
		//find key
		unordered_map<int, Node*>::iterator iter = map_.find(key);
		//if this is a new key, add a new node to deque_
		if(map_.end()==iter){
			//check capacity
			while(capacity_<=(int)map_.size()){
				int key_to_del = deque_.popTail();
				map_.erase(map_.find(key_to_del));
			}
			//add new node
			map_[key] = deque_.addNewNode(key, value);
			//return
			return;
		}
		//if the key exists already, perform update
		deque_.moveToHead(iter->second);
		iter->second->val_ = value;
		return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
