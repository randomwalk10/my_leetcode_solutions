/*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:

The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.
*/

#include <vector>
using namespace std;

struct Node{
	Node* zero_;
	Node* one_;
	int cnt_;
	Node(): zero_(NULL), one_(NULL), cnt_(0){}
};

class Solution {
	int count(int input, Node* header){
		int half = (input>>1);
		half |= input&(1<<31);// keep the - sign if there is one
		bool isOdd = input&0x1;
		int res = 0;
		// count all numbers that is less than half
		// if isOdd==true, count numbers that equals half as well
		int bit_pos = 31;
		int mask;
		while(header&&(bit_pos>=0)){
			// update mask
			mask = 1<<bit_pos;
			// update res
			if( (mask<0)&&((half&mask)==0)&&(header->one_) ){
				res += header->one_->cnt_;
			}	
			else if( (mask>0)&&(half&mask)&&(header->zero_) ){
				res += header->zero_->cnt_;
			}
			// move header to its child
			header = (half&mask)?header->one_:header->zero_;
			// update bit_pos;
			--bit_pos;
		}
		if(header&&isOdd) res += header->cnt_;
		// return
		return res;
	}
	void update(int input, Node* header){
		int bit_pos = 31;
		int mask;
		while(bit_pos>=0){
			// update mask
			mask = 1<<bit_pos;
			// update header
			if(input&mask){
				if(NULL==header->one_){
					header->one_ = new Node();
				}
				header->one_->cnt_ += 1;
				header = header->one_;
			}
			else{
				if(NULL==header->zero_){
					header->zero_ = new Node();
				}
				header->zero_->cnt_ += 1;
				header = header->zero_;
			}
			// update bit_pos
			--bit_pos;
		}
	}
public:
    int reversePairs(vector<int>& nums) {
		if(nums.size()<2) return 0;
		int res = 0;
		int len = nums.size();
		Node* header = new Node(); // head of a list that counts the number of integers at each bit position

		// iterate backwards through nums
		for(int i=len-1; i>=0; --i){
			// update res with half of nums[i]
			res += count(nums[i], header);
			// add nums[i] into the list
			update(nums[i], header);
		}

		// return
		return res;
    }
};
