/*
Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
Example:

Given the following binary tree,

     1
   /  \
  2    3
 / \    \
4   5    7
After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#include <vector>
using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void buildupLayers(TreeLinkNode *root, \
			vector<vector<TreeLinkNode*>> &layers, \
			int base_index){
		if(root==NULL) return;
		if((int)layers.size()<=base_index){
			vector<TreeLinkNode*> temp = {root};
			layers.push_back(temp);
		}
		else{
			layers[base_index].push_back(root);
		}

		buildupLayers(root->left, layers, base_index+1);
		buildupLayers(root->right, layers, base_index+1);
	}

    void connect(TreeLinkNode *root) {
		vector<vector<TreeLinkNode*>> layers;
		buildupLayers(root, layers, 0);

		for(size_t i=0; i<layers.size(); ++i){
			for(size_t j=0; j<layers[i].size(); ++j){
				if((j+1)<layers[i].size())
					layers[i][j]->next = layers[i][j+1];
				else
					layers[i][j]->next = NULL;
			}
		}
    }
};
