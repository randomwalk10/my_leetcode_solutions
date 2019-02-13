/*
 One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:

Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
Example 2:

Input: "1,#"
Output: false
Example 3:

Input: "9,#,#,1"
Output: false
*/
#include <string>
using namespace std;

class Solution {
private:
	int isValidSerialization(string& preorder, int start){
		//check if start exceeds limits and skip the first comma if possible
		if(start>(int)preorder.size()) return -1;//error
		else if(preorder[start]==',') ++start;//skip the first comma

		//check if it reaches the end of tree
		if(preorder[start]=='#') return start+1;

		//find the next comma
		while( (start<(int)preorder.size())&&(preorder[start]!=',') ){
			++start;
		}
		if(start>=(int)preorder.size()) return -1;

		//left
		int next_idx = isValidSerialization(preorder, start+1);
		if(next_idx<0) return next_idx;
		//right
		next_idx = isValidSerialization(preorder, next_idx);
		if(next_idx<0) return next_idx;
		//return
		return next_idx;
	}
public:
    bool isValidSerialization(string preorder) {
		return isValidSerialization(preorder, 0) == (int)preorder.size();
    }
};
