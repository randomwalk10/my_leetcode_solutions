/*
Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.

 

Example 1:

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
 

Note:

1 <= pre.length == post.length <= 30
pre[] and post[] are both permutations of 1, 2, ..., pre.length.
It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post, \
			int pre_l, int pre_r, int post_l, int post_r, vector<int>& val2postidx){
		if(pre_l>pre_r) return NULL;
		// root
		TreeNode* head = new TreeNode(pre[pre_l]);
		// trasverse to child nodes
		if(pre_l<pre_r){
			// left child
			int left_l = pre_l + 1;
			int right_r= val2postidx[pre[left_l]-1];
			int left_r = left_l + right_r - post_l;
			int right_l = post_l;
			head->left = constructFromPrePost(pre, post, left_l, left_r, \
					right_l, right_r, val2postidx);
			// right child
			if(right_r!=post_r-1){
				left_l = left_r + 1;
				left_r = pre_r;
				right_l = right_r + 1;
				right_r = post_r - 1;
				head->right = constructFromPrePost(pre, post, left_l, left_r, \
						right_l, right_r, val2postidx);
			}
		}
		// retur root
		return head;
	}
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		vector<int> val2postidx(post.size(), 0);
		for(int i=0; i<(int)post.size(); ++i){
			val2postidx[post[i]-1] = i;
		}
		return constructFromPrePost(pre, post, 0, pre.size()-1, 0, post.size()-1, val2postidx);
    }
};
