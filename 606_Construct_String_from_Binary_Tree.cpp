/*
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)".
Example 2:
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example, 
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-string-from-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stack>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    string tree2str(TreeNode* t) {
		string res;
		if(NULL==t) return res;
		stack<TreeNode*> s_parent;
		stack<bool> s_visited;

		s_parent.push(t);
		s_visited.push(false);
		bool is_first = true;
		while(!s_parent.empty()){
			TreeNode* tmp_node = s_parent.top(); s_parent.pop();
			bool is_visited = s_visited.top(); s_visited.pop();

			if(is_visited){
				res.push_back(')');
			}
			else{
				if(false==is_first) res.push_back('(');

				int temp = tmp_node->val;
				stack<char> s_digit;
				if(temp<0){
					res.push_back('-');
					temp = -temp;
				}
				do {
					s_digit.push((temp%10)+'0');
					temp /= 10;
				} while (temp>0);
				while(!s_digit.empty()){
					res.push_back(s_digit.top()); s_digit.pop();
				}

				if(is_first) is_first=false;
				else{
					s_parent.push(tmp_node);
					s_visited.push(true);
				}
				if(tmp_node->right){
					s_parent.push(tmp_node->right);
					s_visited.push(false);
				}
				if(tmp_node->left){
					s_parent.push(tmp_node->left);
					s_visited.push(false);
				}
				else if(tmp_node->right){
					res.push_back('(');
					res.push_back(')');
				}
			}
		}

		return res;
    }
};
