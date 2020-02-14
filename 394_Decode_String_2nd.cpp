/* iteration solution */
/* O(N) in time and O(N) in space, where N is the output length */
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> c;
        stack<string> l;

        int i=0;
        string cur;
        int cnt;
        while(i<(int)s.size()){
            if( (s[i]<='9')&&(s[i]>='0') ){
                c.push(cnt);
                l.push(cur);
                cnt = 0;
                cur.clear();
                while(s[i]!='['){
                    cnt = cnt * 10 + s[i] - '0';
                    ++i;
                }
                ++i;
            }
            else if(s[i]==']'){
                string temp = l.top(); l.pop();
                for(int j=0; j<cnt; ++j){
                    temp.append(cur);
                }
                cur = temp;
                cnt = c.top(); c.pop();
                ++i;
            }
            else{
                cur.push_back(s[i]);
                ++i;
            }
        }
        
        return cur;
    }
};
