/*
T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create an algorithm to determine if T2 is a subtree of T1.

A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2. That is, if you cut off the tree at node n, the two trees would be identical.

Example1:

 Input: t1 = [1, 2, 3], t2 = [2]
 Output: true
Example2:

 Input: t1 = [1, null, 2, 4], t2 = [3, 2]
 Output: false
Note:

The node numbers of both tree are in [0, 20000].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-subtree-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#define NULL 0

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool isSame(TreeNode* t1, TreeNode* t2){
		if((NULL==t1)&&(NULL==t2)) return true;
		else if((NULL==t1)||(NULL==t2)) return false;
		return (t1->val==t2->val)&&isSame(t1->left, t2->left)&&isSame(t1->right, t2->right);
	}
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
		if(isSame(t1, t2)) return true;
		else if((NULL!=t1)&&checkSubTree(t1->left, t2)) return true;
		else if((NULL!=t1)&&checkSubTree(t1->right, t2)) return true;
		return false;
    }
};
