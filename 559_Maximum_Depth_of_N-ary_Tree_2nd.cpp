/* iterative solution
 * O(N) in time and O(N) in space
 */
#include <vector>
#include <stack>
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
		int maxDepth(Node* root) {
			if(root==NULL) return 0;
			int res = 0;
			stack<Node*> s_node;
			stack<int> s_depth;

			s_node.push(root);
			s_depth.push(1);

			while(!s_node.empty()){
				Node* tmp_node = s_node.top(); s_node.pop();
				int tmp_depth = s_depth.top(); s_depth.pop();
				res = max(res, tmp_depth);

				for(int i=0; i<(int)tmp_node->children.size(); ++i){
					if(tmp_node->children[i]){
						s_node.push(tmp_node->children[i]);
						s_depth.push(tmp_depth+1);
					}
				}
			}

			return res;
		}
};
