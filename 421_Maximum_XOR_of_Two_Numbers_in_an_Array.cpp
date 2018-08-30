/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 2^31.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/
#include <vector>
#include <unordered_set>
using namespace std;

/*solution 1: hash set
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
		int res = 0;
		int mask = 0;

		for(int i=30; i>=0; --i){
			mask |= 1<<i;
			unordered_set<int> _hash_set;
			for(size_t j=0; j<nums.size(); ++j){
				_hash_set.insert( nums[j] & mask );
			}

			int temp = res | (1<<i);
			for(unordered_set<int>::iterator iter = _hash_set.begin();
					iter != _hash_set.end(); ++iter){
				if( _hash_set.find( temp ^ (*iter) ) != _hash_set.end() ){
					res = temp;
					break;
				}
			}
		}

		return res;
    }
};
*/

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int val): left(NULL), right(NULL), val(val){}
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
		int res = 0;

		//build tree
		TreeNode* root = new TreeNode(0);
		for(size_t i=0; i<nums.size(); ++i){
			TreeNode* temp = root;
			for(int j=30; j>=0; --j){
				int mask = (1<<j);
				if(mask&nums[i]){
					if(NULL==temp->right)
						temp->right = new TreeNode(1);
					temp = temp->right;
				}
				else{
					if(NULL==temp->left)
						temp->left = new TreeNode(0);
					temp = temp->left;
				}
			}
		}
		//find max
		for(size_t i=0; i<nums.size(); ++i){
			TreeNode* temp = root;
			int exclusive_or = 0;
			for(int j=30; j>=0; --j){
				int mask = (1<<j);
				if(mask&nums[i]){
					if(temp->left){
						exclusive_or |= mask;
						temp = temp->left;
					}
					else{
						temp = temp->right;
					}
				}
				else{
					if(temp->right){
						exclusive_or |= mask;
						temp = temp->right;
					}
					else{
						temp = temp->left;
					}
				}
			}
			res = (exclusive_or>res)?exclusive_or:res;
		}

		return res;
    }
};
