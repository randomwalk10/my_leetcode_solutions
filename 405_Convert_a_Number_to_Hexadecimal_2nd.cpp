#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        string res;
        stack<char> s;

        unsigned int n = num;
        while(n>0){
            int r = n%16;
            n /= 16;
            if(r<10) s.push('0'+r);
            else s.push('a'+r-10);
        }

        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }

        return res;
    }
};
