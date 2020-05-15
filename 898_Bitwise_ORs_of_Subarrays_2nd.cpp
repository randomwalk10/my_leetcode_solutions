/* O(N^2) in time and O(N^2) in space
 *
 * Could be N^2 in the worst scenario.
 * but this method is faster than the first one in practice
 */

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res;

        for(int i=0; i<(int)A.size(); ++i){
            res.insert(A[i]);
            for(int j=i-1; j>=0; --j){
                if((A[j]|A[i])==A[j]) break;
                A[j] |= A[i];
                res.insert(A[j]);
            }
        }

        return res.size();
    }
};
