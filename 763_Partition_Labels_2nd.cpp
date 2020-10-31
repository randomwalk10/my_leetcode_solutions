#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        vector<int> pos(26, 0);
        int i = 0;
        for(i = 0; i<S.size(); ++i){
            pos[S[i]-'a'] = i;
        }
        i = 0;
        int l = 0, r = 0;
        while(i<S.size()){
            r = max(r, pos[S[i]-'a']);
            if(i==r){
                res.push_back(r-l+1);
                ++r; l = r;
            }
            ++i;
        }
        return res;
    }
};
