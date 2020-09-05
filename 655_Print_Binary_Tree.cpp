/*
Print a binary tree in an m*n 2D string array following these rules:

The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
Each unused space should contain an empty string "".
Print the subtrees following the same rules.
Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]
Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
Example 3:
Input:
      1
     / \
    2   5
   / 
  3 
 / 
4 
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
Note: The height of binary tree is in the range of [1, 10].



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/print-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
		vector<vector<string>> res;
		stack<TreeNode*> s;
		stack<int> s_d;
		int max_d = -1;

		if(root){
			s.push(root);
			s_d.push(0);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int d = s_d.top(); s_d.pop();

			if(d>max_d) max_d = d;

			if(tmp->right){
				s.push(tmp->right);
				s_d.push(d+1);
			}
			if(tmp->left){
				s.push(tmp->left);
				s_d.push(d+1);
			}
		}

		stack<int> s_l, s_r;
		int cols = pow(2, max_d+1)-1;
		res = vector<vector<string>>(max_d+1, vector<string>(cols, ""));
		if(root){
			s.push(root);
			s_d.push(0);
			s_l.push(0);
			s_r.push(cols-1);
		}
		while(!s.empty()){
			TreeNode* tmp = s.top(); s.pop();
			int d = s_d.top(); s_d.pop();
			int l = s_l.top(); s_l.pop();
			int r = s_r.top(); s_r.pop();

			int mid = l + (r-l)/2;
			res[d][mid] = std::to_string(tmp->val);

			if(tmp->right){
				s.push(tmp->right);
				s_d.push(d+1);
				s_l.push(mid+1);
				s_r.push(r);
			}
			if(tmp->left){
				s.push(tmp->left);
				s_d.push(d+1);
				s_l.push(l);
				s_r.push(mid-1);
			}
		}

		return res;
    }
};
