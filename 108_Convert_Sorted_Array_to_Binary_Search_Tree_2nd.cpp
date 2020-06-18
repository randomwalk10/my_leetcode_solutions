/* iteration solution
 * O(N) in time and O(N) in space
 * */
#include <stack>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	public:
		TreeNode* sortedArrayToBST(vector<int>& nums) {
			stack<TreeNode*> s_parent;
			stack<bool> s_is_left;
			stack<int> l;
			stack<int> r;
			TreeNode* res = NULL;

			s_parent.push(NULL);
			s_is_left.push(true);
			l.push(0);
			r.push(nums.size()-1);

			while(!s_parent.empty()){
				TreeNode* parent_node = s_parent.top(); s_parent.pop();
				bool is_left = s_is_left.top(); s_is_left.pop(); 
				int tmp_l = l.top(); l.pop();
				int tmp_r = r.top(); r.pop();

				if(tmp_l<=tmp_r){
					int mid = tmp_l+((tmp_r-tmp_l)>>1);
					TreeNode* new_node = new TreeNode(nums[mid]);
					if(parent_node)
						if(is_left) parent_node->left = new_node;
						else parent_node->right = new_node;
					else res = new_node;
					// left
					s_parent.push(new_node);
					s_is_left.push(true);
					l.push(tmp_l);
					r.push(mid-1);
					// right
					s_parent.push(new_node);
					s_is_left.push(false);
					l.push(mid+1);
					r.push(tmp_r);
				}
				else{
					if(parent_node)
						if(is_left) parent_node->left = NULL;
						else parent_node->right = NULL;
					else res = NULL;
				}
			}

			return res;        
		}
};
