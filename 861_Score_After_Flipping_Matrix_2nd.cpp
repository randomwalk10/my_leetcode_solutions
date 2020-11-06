#include <vector>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
		int res1 = 0, res2 = 0;
		const int rows = A.size();
		const int cols = A[0].size();

		for (size_t c = 0; c < cols; ++c) {
			if(0==c){
				res1 += A.size() * (1<<(cols-1));
				continue;
			}
			int ones = 0;
			for (size_t r = 0; r < rows; ++r) {
				ones += (A[r][0])?A[r][c]:(1-A[r][c]);
			}
			res1 += max(ones, rows-ones) * (1<<(cols-c-1));
		}

		/* symmetric to res1 problem
		for (size_t c = 0; c < cols; ++c) {
			if(0==c){
				res2 += A.size() * (1<<(cols-1));
				continue;
			}
			int ones = 0;
			for (size_t r = 0; r < rows; ++r) {
				ones += (A[r][0]==0)?A[r][c]:(1-A[r][c]);
			}
			res2 += max(ones, rows-ones) * (1<<(cols-c-1));
		}
		*/

		return max(res1, res2);
    }
};
