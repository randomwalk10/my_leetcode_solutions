/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
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
#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
		TreeNode* head = root;
		TreeNode* parent = NULL;
		//search for node with value==key
		while(head){
			if(head->val==key) break;
			else if(head->val<key){
				parent = head;
				head = head->right;
			}
			else{
				parent = head;
				head = head->left;
			}
		}
		if(head==NULL) return root;
		//delete node with tree re-arrangement
		if(head->left){
			//find the largest node of left subtree of head
			TreeNode* temp = head->left;
			parent = head;
			while(temp->right){
				parent = temp;
				temp = temp->right;
			}
			//delete
			head->val = temp->val;
			if(head==parent) parent->left = temp->left;
			else parent->right = temp->left;
			delete temp;
		}
		else if(head->right){
			//find the smallest node of right subtree of head
			TreeNode* temp = head->right;
			parent = head;
			while(temp->left){
				parent = temp;
				temp = temp->left;
			}
			//delete
			head->val = temp->val;
			if(head==parent) parent->right = temp->right;
			else parent->left = temp->right;
			delete temp;
		}
		else{
			if(head==root){
				delete head;
				return NULL;
			}
			if(parent->left==head) parent->left = NULL;
			else parent->right = NULL;
			delete head;
		}
		//return
		return root;
    }
};
