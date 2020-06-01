/*
Given an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Follow up:

Recursive solution is trivial, could you do it iteratively?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(N) in time and O(N) in space */
#include <vector>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root==NULL) return {};
        stack<Node*> s;
        stack<bool> expanded;
        vector<int> res;

        s.push(root);
        expanded.push(false);
        while(!s.empty()){
            Node* temp = s.top(); s.pop();
            bool is_expanded = expanded.top(); expanded.pop();
            if(is_expanded){
                res.push_back(temp->val);
                continue;
            }
            s.push(temp);
            expanded.push(true);
            for(int i=(int)temp->children.size()-1; i>=0; --i){
                if(NULL!=temp->children[i]){
                    s.push(temp->children[i]);
                    expanded.push(false);
                }
            }
        }

        return res;
    }
};
