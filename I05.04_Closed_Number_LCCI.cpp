/*
Given a positive integer, print the next smallest and the next largest number that have the same number of 1 bits in their binary representation.

Example1:

 Input: num = 2 (0b10)
 Output: [4, 1] ([0b100, 0b1])
Example2:

 Input: num = 1
 Output: [2, -1]
Note:

1 <= num <= 2147483647
If there is no next smallest or next largest number, output -1.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/closed-number-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        vector<int> res = {-1, -1};

        if(num!=2147483647){
            int ones = 0;
            for(int i=0; i<30; ++i){
                if((1<<i)&num){
                    if((1<<(i+1))&num){
                        ;
                    }
                    else{
                        res[0] = (num | (1<<(i+1))) & (~(1<<i));
                        if(ones>0){
                            res[0] &= (~((1<<i) - 1));
                            res[0] |= (1<<ones) - 1;
                        }
                        break;
                    }
                    ++ones;
                }
            }
        }

        if(num!=1){
            int ones = 0;
            for(int i=0; i<30; ++i){
                if((1<<i)&num){
                    ++ones;
                }
                else{
                    if((1<<(i+1))&num){
                        res[1] = (num | (1<<i)) & (~(1<<(i+1)));
                        if(ones>0){
                            res[1] &= (~((1<<i) - 1));
                            res[1] |= ((1<<ones)-1)<<(i-ones);
                        }
                        break;
                    }
                }
            }
        }

        return res;
    }
};
