/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int getSum(int a, int b) {
        int res=0;
        int i=0;
        bool is_carry = false;
        for(i=0; i<31; ++i){
            int mask = 1<<i;
            if( (a&mask)&&(b&mask)&&is_carry ){
                is_carry = true;
                res |= mask;
            }
            else if( ((a&mask)&&(b&mask)) || ((b&mask)&&is_carry) || \
                    ((a&mask)&&is_carry) ){
                is_carry = true;
                res &= ~mask;
            }
            else if( (a&mask) || (b&mask) || is_carry ){
                is_carry = false;
                res |= mask;
            }
            else{
                is_carry = false;
                res &= ~mask;
            }
        }
        int mask = 1<<i;
        if( is_carry&&(a&mask)&&(b&mask) ) res |= mask;
        else if( is_carry&&((a&mask)||(b&mask)) ) res &= ~mask;
        else if( (a&mask)||(b&mask) ) res |= mask;
        return res;
    }
};
