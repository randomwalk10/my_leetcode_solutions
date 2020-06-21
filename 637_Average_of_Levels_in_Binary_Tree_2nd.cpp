#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
		if(root==NULL) return {};
		stack<TreeNode*> s_parent;
		stack<int> s_depth;
		vector<double> sums;
		vector<int> counts;

		s_parent.push(root);
		s_depth.push(1);
		while(!s_parent.empty()){
			TreeNode* tmp_node = s_parent.top(); s_parent.pop();
			int tmp_depth = s_depth.top(); s_depth.pop();

			if(tmp_depth>(int)sums.size()){
				sums.push_back((double)(tmp_node->val));
				counts.push_back(1);
			}
			else{
				sums[tmp_depth-1] += (double)(tmp_node->val);
				counts[tmp_depth-1] += 1;
			}

			if(tmp_node->right){
				s_parent.push(tmp_node->right);
				s_depth.push(tmp_depth+1);
			}
			if(tmp_node->left){
				s_parent.push(tmp_node->left);
				s_depth.push(tmp_depth+1);
			}
		}

		for (int i = 0; i < (int)sums.size(); ++i) {
			sums[i] /= counts[i];
		}

		return sums;
    }
};
