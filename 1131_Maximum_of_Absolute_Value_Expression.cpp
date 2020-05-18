/*
Given two arrays of integers with equal lengths, return the maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

where the maximum is taken over all 0 <= i, j < arr1.length.

 

Example 1:

Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
Output: 13
Example 2:

Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
Output: 20
 

Constraints:

2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-of-absolute-value-expression
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(N) in time and O(1) in space */
#include <vector>
using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
		vector<int> max_val(8, 0);
		vector<int> min_val(8, 0);
		int i;

		for (i = 0; i < (int)arr1.size(); ++i) {
			int temp1 = arr1[i] + arr2[i] + i;
			int temp2 = arr1[i] + arr2[i] - i;
			int temp3 = arr1[i] - arr2[i] + i;
			int temp4 = arr1[i] - arr2[i] - i;
			int temp5 = -arr1[i] + arr2[i] + i;
			int temp6 = -arr1[i] + arr2[i] - i;
			int temp7 = -arr1[i] - arr2[i] + i;
			int temp8 = -arr1[i] - arr2[i] - i;
			if(i==0){
				max_val[0] = temp1;
				max_val[1] = temp2;
				max_val[2] = temp3;
				max_val[3] = temp4;
				max_val[4] = temp5;
				max_val[5] = temp6;
				max_val[6] = temp7;
				max_val[7] = temp8;
				min_val[0] = temp1;
				min_val[1] = temp2;
				min_val[2] = temp3;
				min_val[3] = temp4;
				min_val[4] = temp5;
				min_val[5] = temp6;
				min_val[6] = temp7;
				min_val[7] = temp8;
			}
			else{
				max_val[0] = max(temp1, max_val[0]);
				max_val[1] = max(temp2, max_val[1]);
				max_val[2] = max(temp3, max_val[2]);
				max_val[3] = max(temp4, max_val[3]);
				max_val[4] = max(temp5, max_val[4]);
				max_val[5] = max(temp6, max_val[5]);
				max_val[6] = max(temp7, max_val[6]);
				max_val[7] = max(temp8, max_val[7]);
				min_val[0] = min(temp1, min_val[0]);
				min_val[1] = min(temp2, min_val[1]);
				min_val[2] = min(temp3, min_val[2]);
				min_val[3] = min(temp4, min_val[3]);
				min_val[4] = min(temp5, min_val[4]);
				min_val[5] = min(temp6, min_val[5]);
				min_val[6] = min(temp7, min_val[6]);
				min_val[7] = min(temp8, min_val[7]);
			}
		}

		int res=0;
		for (i = 0; i < (int)max_val.size(); ++i) {
			res = max(max_val[i]-min_val[i], res);
		}
		return res;
    }
};
