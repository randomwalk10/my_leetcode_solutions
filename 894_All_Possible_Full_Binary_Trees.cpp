/*
A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.

Note:

1 <= N <= 20
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
public:
    vector<TreeNode*> allPossibleFBT(int N) {
		vector<TreeNode*> out;
		if(N%2==0) return out;

		if(N==1) out.push_back(new TreeNode(0));
		else{
			for(int l=1; l<N-1; l+=2){
				vector<TreeNode*> left_trees = allPossibleFBT(l);
				vector<TreeNode*> right_trees = allPossibleFBT(N-1-l);

				for(size_t i=0; i<left_trees.size(); ++i){
					for(size_t j=0; j<right_trees.size(); ++j){
						TreeNode* temp = new TreeNode(0);
						temp->left = left_trees[i];
						temp->right = right_trees[j];
						out.push_back(temp);
					}
				}
			}
		}

		return out;
    }
};
