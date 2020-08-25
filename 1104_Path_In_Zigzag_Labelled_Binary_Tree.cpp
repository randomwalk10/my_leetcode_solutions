/*
In an infinite binary tree where every node has two children, the nodes are labelled in row order.

In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.



Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.

 

Example 1:

Input: label = 14
Output: [1,3,4,14]
Example 2:

Input: label = 26
Output: [1,2,6,10,26]
 

Constraints:

1 <= label <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
		vector<int> res;
		int row = ceil(log2(label+1));
		res = vector<int>(row, 0);
		for (int r = row; r >= 1; --r) {
			res[r-1] = label;

			int base = pow(2, r-1) - 1;
			label = base - (label - base - 1) / 2;
		}
		return res;
    }
};
