/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<int> _s_val;
public:
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> s_parent;
        stack<bool> s_visited;
        
        if(root){
            s_parent.push(root);
            s_visited.push(false);
        }
        while(!s_parent.empty()){
            TreeNode* tmp = s_parent.top(); s_parent.pop();
            bool is_visited = s_visited.top(); s_visited.pop();
            if(is_visited){
                _s_val.push(tmp->val);
            }
            else{
                //left
                if(tmp->left){
                    s_parent.push(tmp->left);
                    s_visited.push(false);
                }
                //self
                s_parent.push(tmp);
                s_visited.push(true);
                //right
                if(tmp->right){
                    s_parent.push(tmp->right);
                    s_visited.push(false);
                }
            }
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int res = _s_val.top(); _s_val.pop();
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !_s_val.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
