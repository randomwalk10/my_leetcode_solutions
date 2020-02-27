/* O(N) in time and O(1) in space */
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1;
        int j = T.size() - 1;
        while(true){
            int bcnt = 0;
            while( (i>=0)&&( (S[i]=='#')||(bcnt>0) ) ){
                if(S[i]=='#') ++bcnt;
                else --bcnt;
                --i;
            }
            bcnt = 0;
            while( (j>=0)&&( (T[j]=='#')||(bcnt>0) ) ){
                if(T[j]=='#') ++bcnt;
                else --bcnt;
                --j;
            }

            if( (i<0)&&(j<0) ) break;
            else if(i<0) return false;
            else if(j<0) return false;
            else if(S[i]==T[j]){
                --i; --j;
            }
            else return false;
        }
        return true;
    }
};
