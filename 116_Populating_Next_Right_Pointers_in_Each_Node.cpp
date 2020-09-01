/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

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
		Node* res = root;
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

			if(d>=tails.size()){
				tails.push_back({tmp});
			}
			else{
				tails[d]->next = tmp;
				tails[d] = tmp;
			}

			//right
			if(tmp->right){
				s.push(tmp->right);
				s_d.push(d+1);
			}
			//left
			if(tmp->left){
				s.push(tmp->left);
				s_d.push(d+1);
			}
		}

		return res;
    }
};
