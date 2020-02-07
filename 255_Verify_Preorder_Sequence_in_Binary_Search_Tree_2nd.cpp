#include <vector>
using namespace std;

/* O(N) in time and O(1) in space */
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
		int i, j=-1;
		int min_val = INT_MIN;
		for (i = 0; i < (int)preorder.size(); ++i) {
			if(min_val>=preorder[i]) return false;

			while((j>=0)&&(preorder[j]<preorder[i])){
				min_val = preorder[j--];
			}

			preorder[++j] = preorder[i];
		}
		return true;
    }
};
