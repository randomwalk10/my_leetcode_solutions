#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int l=0, r=0;
        int ng = g.size(), ns = s.size();

        while((l<ng)&&(r<ns)){
            if(g[l]<=s[r]){
                ++l; ++r;
            }
            else if(g[l]>s[ns-1]) break;
            else ++r;
        }

        return l;
    }
};
