/* O(N) in time and O(1) in space */
#include <string>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty()) return false;
        int res = 1;

        int i=0;
        while(i<(int)preorder.size()){
            while( (i<(int)preorder.size())&&(preorder[i]!=',') ){
                ++i;
            }
            if(preorder[i-1]=='#'){
                --res;
            }
            else{
                ++res;
            }

            if( (i<(int)preorder.size())&&(res==0) ){
                return false;
            }
            ++i;
        }

        return res==0;
    }
};
