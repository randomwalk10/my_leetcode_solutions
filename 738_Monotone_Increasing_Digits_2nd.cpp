#include <deque>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if(N==0) return 0;
        deque<int> digits;

        while(N>0){
            digits.push_front(N%10);
            N /= 10;
        }

        for(int i=1; i<digits.size(); ++i){
            if(digits[i]<digits[i-1]){
                int temp = i-1;
                while((temp>0)&&(digits[temp]==digits[temp-1])){
                    --temp;
                }
                --digits[temp];
                for (int j = temp+1; j < digits.size(); ++j)
                {
                    digits[j] = 9;
                }
                break;
            }
        }

        int res = 0;
        for(int t: digits){
            res = res*10 + t;
        }

        return res;
    }
};