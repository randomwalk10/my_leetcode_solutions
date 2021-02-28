/*
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.

 

Example 1:

Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
Example 2:

Input: boxes = "001011"
Output: [11,8,5,4,3,4]
 

Constraints:

n == boxes.length
1 <= n <= 2000
boxes[i] is either '0' or '1'.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
		vector<int> res(boxes.size(), 0);
		int le_sum=0, g_sum=0;
		int le_cnt=0, g_cnt=0;

		if(boxes[0]=='1'){
			le_cnt = 1;
		}
		for (int i = 1; i < (int)boxes.size(); ++i) {
			if(boxes[i]=='1'){
				++g_cnt;
				g_sum += i;
			}
		}

		res[0] = le_sum + g_sum;
		for (int i = 1; i < (int)boxes.size(); ++i) {
			if(boxes[i]=='1'){
				le_sum += le_cnt;
				g_sum -= g_cnt;
				++le_cnt;
				--g_cnt;
			}
			else{
				le_sum += le_cnt;
				g_sum -= g_cnt;
			}
			res[i] = le_sum + g_sum;
		}

		return res;
    }
};
