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
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    vector<int> _ranked;
    int _i;
public:
    BSTIterator(TreeNode* root) {
        _i = 0;
        stack<TreeNode*> s;

        while( (!s.empty())||(root!=NULL) ){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top(); s.pop();
            _ranked.push_back(root->val);
            root = root->right;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        return _ranked[_i++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return _i<(int)_ranked.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
