/*
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf if and only if it has 0 children.)
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.

 

Example 1:

Input: arr = [6,2,4]
Output: 32
Explanation:
There are two possible trees.  The first has non-leaf node sum 36, and the second has non-leaf node sum 32.

    24            24
   /  \          /  \
  12   4        6    8
 /  \               / \
6    2             2   4
 

Constraints:

2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (ie. it is less than 2^31).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-tree-from-leaf-values
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
private:
	void mctFromLeafValues(vector<int>& arr, int l, int r,
			vector<vector<int>>& max_leaf, vector<vector<int>>& min_product){
		for (int i = l; i < r; ++i) {
			if(min_product[l][i]==0)
				mctFromLeafValues(arr, l, i, max_leaf, min_product);
			if(min_product[i+1][r]==0)
				mctFromLeafValues(arr, i+1, r, max_leaf, min_product);
			max_leaf[l][r] = max(max_leaf[l][i], max_leaf[i+1][r]);
			int temp = max_leaf[l][i]*max_leaf[i+1][r] + \
					   min_product[l][i] + min_product[i+1][r];
			if(min_product[l][r]==0)
				min_product[l][r] = temp;
			else
				min_product[l][r] = min(temp, min_product[l][r]);
		}
	}
public:
    int mctFromLeafValues(vector<int>& arr) {
		int N = arr.size();
		vector<vector<int>> max_leaf(N, vector<int>(N, 0));
		vector<vector<int>> min_product(N, vector<int>(N, 0));

		for (int i = 0; i < N; ++i) {
			max_leaf[i][i] = arr[i];
		}

		mctFromLeafValues(arr, 0, N-1, max_leaf, min_product);

		return min_product[0][N-1];
    }
};
