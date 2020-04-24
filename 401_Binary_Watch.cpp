/*
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-watch
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int hour_mask = 0b1111000000;
    int minute_mask = 0b0000111111;
    void readBinaryWatch(int num, int idx, int ones_cnt, int bits, vector<string>& res){
        if(ones_cnt==num){
            // append to res
            int hour = (bits&hour_mask)>>6;
            int minute = (bits&minute_mask);
            if( (hour<12)&&(minute<60) ){
                string temp;
                if(hour/10) temp.push_back('1');
                temp.push_back(hour%10+'0');
                temp.push_back(':');
                temp.push_back(minute/10+'0');
                temp.push_back(minute%10+'0');
                res.push_back(temp);
            }
            return;
        }
        else if(num-ones_cnt+idx-1>=10) return;
        readBinaryWatch(num, idx+1, ones_cnt, bits, res);
        readBinaryWatch(num, idx+1, ones_cnt+1, bits|(1<<idx), res);
    }
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        readBinaryWatch(num, 0, 0, 0, res);
        return res;
    }
};
