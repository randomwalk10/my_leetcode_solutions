/* O(N) in time and O(N) in space */
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        for(int i=1; i<=num; ++i){
            res.push_back(res[i>>1]+(i&0x1));
        }
        return res;
    }
};
