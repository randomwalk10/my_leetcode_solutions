/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        stack<int> c;
        vector<int> res;
        
        if(root){
            s.push(root); c.push(0);
        }
        while(!s.empty()){
            root = s.top(); s.pop();
            int cnt = c.top(); c.pop();

            if(cnt){
                res.push_back(root->val);
            }
            else{
                s.push(root); c.push(1);
                if(root->right){
                    s.push(root->right);
                    c.push(0);
                }
                if(root->left){
                    s.push(root->left);
                    c.push(0);
                }
            }
        }

        return res;
    }
};
