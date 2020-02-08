#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		int i, j=-1;
		for (i = 0; i < (int)s.size(); ++i) {
			if( (s[i]=='(')||(s[i]=='{')||(s[i]=='[') ){
				s[++j] = s[i];
			}
			else if(s[i]==')'){
				if( (j<0)||(s[j]!='(') )
					return false;
				else
					--j;
			}
			else if(s[i]=='}'){
				if( (j<0)||(s[j]!='{') )
					return false;
				else
					--j;
			}
			else{
				if( (j<0)||(s[j]!='[') )
					return false;
				else
					--j;
			}
		}
        
		return (j<0);
    }
};
