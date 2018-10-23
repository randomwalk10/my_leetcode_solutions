/*
Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].

Return any permutation of A that maximizes its advantage with respect to B.

 

Example 1:

Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]
Example 2:

Input: A = [12,24,8,32], B = [13,25,32,11]
Output: [24,32,8,12]
 

Note:

1 <= A.length = B.length <= 10000
0 <= A[i] <= 10^9
0 <= B[i] <= 10^9
*/
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
		vector<int> out(A.begin(), A.end());
		if(A.size()<2) return out;

		multiset<int> repo(A.begin(), A.end());
		for(int i=0; i<(int)B.size(); ++i){
			multiset<int>::iterator iter = repo.upper_bound(B[i]);
			iter = (repo.end()==iter) ? repo.begin() : iter;
			out[i] = *iter;
			repo.erase(iter);

		}

		return out;
    }
};
