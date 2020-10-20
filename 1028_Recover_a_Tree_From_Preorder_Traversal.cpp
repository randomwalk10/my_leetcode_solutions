/*
We run a preorder depth first search on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  (If the depth of a node is D, the depth of its immediate child is D+1.  The depth of the root node is 0.)

If a node has only one child, that child is guaranteed to be the left child.

Given the output S of this traversal, recover the tree and return its root.

 

Example 1:



Input: "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
Example 2:



Input: "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]
 

Example 3:



Input: "1-401--349---90--88"
Output: [1,401,null,349,88,90]
 

Note:

The number of nodes in the original tree is between 1 and 1000.
Each node will have a value between 1 and 10^9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
		vector<TreeNode*> trees;
		TreeNode* root = NULL;

		int i = 0;
		while(i<S.size()){
			int d = 0;
			int val = 0;
			while(S[i]=='-'){
				++d; ++i;
			}
			while((i<S.size())&&(S[i]!='-')){
				val = 10*val + (S[i]-'0');
				++i;
			}
			TreeNode* tmp_node = new TreeNode(val);
			if(d<trees.size()){
				trees[d] = tmp_node;
			}
			else{
				trees.push_back(tmp_node);
			}
			if(d==0) root = tmp_node;
			else{
				if(NULL==trees[d-1]->left)
					trees[d-1]->left = tmp_node;
				else
					trees[d-1]->right = tmp_node;
			}
		}

		return root;
    }
};
