/* iterative solution */

#include <string>
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
		vector<string> binaryTreePaths(TreeNode* root) {
			vector<string> res;
			if(root==NULL) return res;
			vector<int> nums;
			stack<TreeNode*> s_parent;
			stack<int> s_depth;
			stack<bool> s_visited;

			s_parent.push(root);
			s_depth.push(1);
			s_visited.push(false);
			while(!s_parent.empty()){
				TreeNode* tmp_node = s_parent.top(); s_parent.pop();
				int tmp_depth = s_depth.top(); s_depth.pop();
				bool tmp_visited = s_visited.top(); s_visited.pop();

				if(tmp_visited){
					while(tmp_depth<(int)nums.size()){
						nums.pop_back();
					}
					if((tmp_node->left==NULL)&&(tmp_node->right==NULL)){
						string tmp_str;
						for (int i = 0; i < (int)nums.size(); ++i) {
							if(i>0) tmp_str.append("->");
							int tmp_val = nums[i];
							if(tmp_val<0){
								tmp_val *= -1;
								tmp_str.push_back('-');
							}
							else if(tmp_val==0){
								tmp_str.push_back('0');
								continue;
							}

							stack<char> s_char;
							while(tmp_val>0){
								s_char.push((tmp_val%10)+'0');
								tmp_val /= 10;
							}
							while(!s_char.empty()){
								tmp_str.push_back(s_char.top());
								s_char.pop();
							}
						}
						res.push_back(tmp_str);
					}
				}
				else{
					//right
					if(tmp_node->right){
						s_parent.push(tmp_node->right);
						s_depth.push(tmp_depth+1);
						s_visited.push(false);
					}
					//parent
					s_parent.push(tmp_node);
					s_depth.push(tmp_depth);
					s_visited.push(true);
					nums.push_back(tmp_node->val);
					//left
					if(tmp_node->left){
						s_parent.push(tmp_node->left);
						s_depth.push(tmp_depth+1);
						s_visited.push(false);
					}
				}
			}

			return res;
		}
};
