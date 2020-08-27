#include <stack>
#include <vector>
using namespace std;

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
    vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> res;
		stack<Node*> s;
		stack<int> s_d;

		if(root){
			s.push(root);
			s_d.push(0);
		}
		while(!s.empty()){
			Node* tmp = s.top(); s.pop();
			int d = s_d.top(); s_d.pop();

			if(d>=res.size()){
				res.push_back({tmp->val});
			}
			else{
				res[d].push_back(tmp->val);
			}

			for(int i=tmp->children.size()-1; i>=0; --i){
				if(tmp->children[i]){
					s.push(tmp->children[i]);
					s_d.push(d+1);
				}
			}
		}
        
		return res;
    }
};
