/*
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

 

Example 1:



Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: 
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).
Example 2:



Input: [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: 
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.
 

Note:

The tree will have between 1 and 1000 nodes.
Each node's value will be between 0 and 1000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
		vector<vector<int>> res;
		vector<vector<vector<int>>> grid;
		stack<TreeNode*> s;
		stack<int> s_y, s_x;

		// search for min_x
		s.push(root);
		s_x.push(0);
		int min_x = 0;
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int x = s_x.top(); s_x.pop();

			if(x<min_x) min_x = x;

			if(tmp->right){
				s.push(tmp->right);
				s_x.push(x+1);
			}
			if(tmp->left){
				s.push(tmp->left);
				s_x.push(x-1);
			}
		}

		// fill in grid;
		s.push(root);
		s_x.push(0);
		s_y.push(0);
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int x = s_x.top(); s_x.pop();
			int y = s_y.top(); s_y.pop();

			while((x-min_x)>=grid.size()){
				grid.push_back(vector<vector<int>>());
			}
			while(y>=grid[x-min_x].size()){
				grid[x-min_x].push_back(vector<int>());
			}
			grid[x-min_x][y].push_back(tmp->val);

			if(tmp->right){
				s.push(tmp->right);
				s_x.push(x+1);
				s_y.push(y+1);
			}
			if(tmp->left){
				s.push(tmp->left);
				s_x.push(x-1);
				s_y.push(y+1);
			}
		}

		// fill in res
		for (size_t x = 0; x < grid.size(); ++x) {
			if(x>=res.size()){
				res.push_back(vector<int>());
			}
			for (size_t y = 0; y < grid[x].size(); ++y) {
				if(grid[x][y].size()>0){
					std::sort(grid[x][y].begin(), grid[x][y].end());
					for (size_t i = 0; i < grid[x][y].size(); ++i) {
						res[x].push_back(grid[x][y][i]);
					}
				}
			}
		}

		return res;
    }
};
