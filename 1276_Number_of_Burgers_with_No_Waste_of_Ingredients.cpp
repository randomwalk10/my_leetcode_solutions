/*
Given two integers tomatoSlices and cheeseSlices. The ingredients of different burgers are as follows:

Jumbo Burger: 4 tomato slices and 1 cheese slice.
Small Burger: 2 Tomato slices and 1 cheese slice.
Return [total_jumbo, total_small] so that the number of remaining tomatoSlices equal to 0 and the number of remaining cheeseSlices equal to 0. If it is not possible to make the remaining tomatoSlices and cheeseSlices equal to 0 return [].

 

Example 1:

Input: tomatoSlices = 16, cheeseSlices = 7
Output: [1,6]
Explantion: To make one jumbo burger and 6 small burgers we need 4*1 + 2*6 = 16 tomato and 1 + 6 = 7 cheese. There will be no remaining ingredients.
Example 2:

Input: tomatoSlices = 17, cheeseSlices = 4
Output: []
Explantion: There will be no way to use all ingredients to make small and jumbo burgers.
Example 3:

Input: tomatoSlices = 4, cheeseSlices = 17
Output: []
Explantion: Making 1 jumbo burger there will be 16 cheese remaining and making 2 small burgers there will be 15 cheese remaining.
Example 4:

Input: tomatoSlices = 0, cheeseSlices = 0
Output: [0,0]
Example 5:

Input: tomatoSlices = 2, cheeseSlices = 1
Output: [0,1]
 

Constraints:

0 <= tomatoSlices <= 10^7
0 <= cheeseSlices <= 10^7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-burgers-with-no-waste-of-ingredients
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int jumbo, small;
        int temp1 = tomatoSlices-2*cheeseSlices;
        int temp2 = 4*cheeseSlices-tomatoSlices;
        if((temp1<0)||(temp1%2)) return {};
        else jumbo = temp1/2;
        if((temp2<0)||temp2%2) return {};
        else small = temp2/2;
        return {jumbo, small};
    }
};