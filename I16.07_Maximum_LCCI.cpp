/*
Write a method that finds the maximum of two numbers. You should not use if-else or any other comparison operator.

Example:

Input:  a = 1, b = 2
Output:  2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int maximum(int a, int b) {
		long long sum = (long long)a+(long long)b;
		long long diff = (long long)a-(long long)b;
		/* diff>>63==0 if diff>=0 else diff>>63==-1 */
		long long abs_diff = (diff^(diff>>63))-(diff>>63);
		return (sum+abs_diff)>>1;
    }
};
