#include <stack>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
		stack<Node*> s;
		stack<int> s_d;
		vector<Node*> tails;

		if(root){
			s.push(root);
			s_d.push(0);
		}
		while(!s.empty()){
			Node* tmp = s.top(); s.pop();
			int d = s_d.top(); s_d.pop();

			if(d<(int)tails.size()){
				tails[d]->next = tmp;
				tails[d] = tmp;
			}
			else{
				tails.push_back(tmp);
			}

			if(tmp->right){
				s.push(tmp->right);
				s_d.push(d+1);
			}
			if(tmp->left){
				s.push(tmp->left);
				s_d.push(d+1);
			}
		}

		return root;
    }
};
