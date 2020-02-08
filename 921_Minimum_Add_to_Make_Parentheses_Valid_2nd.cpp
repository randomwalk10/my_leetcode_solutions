#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string S) {
		int res=0, i, j=0;

		for (i = 0; i < (int)S.size(); ++i) {
			if(S[i]=='('){
				++j;
			}
			else if(j<=0){
				++res;
			}
			else{
				--j;
			}
		}
		res += j;

		return res;
    }
};
