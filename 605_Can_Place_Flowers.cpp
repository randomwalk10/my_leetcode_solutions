/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/can-place-flowers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		for (int i = 0; i < (int)flowerbed.size(); ++i) {
			bool is_ok = flowerbed[i]==0;
			if(false==is_ok) continue;
			if(i>0) is_ok &= flowerbed[i-1]==0;
			if(false==is_ok) continue;
			if(i<(int)flowerbed.size()-1) is_ok &= flowerbed[i+1]==0;
			if(false==is_ok) continue;
			else{
				--n;
				flowerbed[i] = 1;
			}
			if(n==0) break;
		}
		return n<=0;
    }
};
