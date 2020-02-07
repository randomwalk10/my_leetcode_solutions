/*
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Consider the following binary search tree: 

     5
    / \
   2   6
  / \
 1   3
Example 1:

Input: [5,2,6,1,3]
Output: false
Example 2:

Input: [5,2,1,3,6]
Output: true
Follow up:
Could you do it using only constant space complexity?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/verify-preorder-sequence-in-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
private:
	bool verifyPreorder(vector<int>& preorder, int l, int r){
		if(l>=r) return true;

		int i, partition_index=-1;
		// partition
		for(i=l+1; i<=r; ++i){
			if(preorder[i]==preorder[l]) return false;
			else if(preorder[i]>preorder[l]){
				if(partition_index<0) partition_index = i;
			}
			else if(preorder[i]<preorder[l]){
				if(partition_index>=0) return false;
			}
		}
		// left child
		bool res_l;
		if(partition_index<0)
			res_l = verifyPreorder(preorder, l+1, r);
		else
			res_l = verifyPreorder(preorder, l+1, partition_index-1);
		if(false==res_l) return false;
		// right child
		bool res_r=true;
		if(partition_index>=0)
			res_r = verifyPreorder(preorder, partition_index, r); 
		//return
		return res_r;
	}
public:
    bool verifyPreorder(vector<int>& preorder) {
		return verifyPreorder(preorder, 0, (int)preorder.size()-1);
    }
};
