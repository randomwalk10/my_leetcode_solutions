/*
Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we repeat this process K times in total.  (We may choose the same index i multiple times.)

Return the largest possible sum of the array after modifying it in this way.

 

Example 1:

Input: A = [4,2,3], K = 1
Output: 5
Explanation: Choose indices (1,) and A becomes [4,-2,3].
Example 2:

Input: A = [3,-1,0,2], K = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].
Example 3:

Input: A = [2,-3,-1,5,-4], K = 2
Output: 13
Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].
 

Note:

1 <= A.length <= 10000
1 <= K <= 10000
-100 <= A[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
		vector<int> pos;
		vector<int> neg;
		int sum = 0;

		for (size_t i = 0; i < A.size(); ++i) {
			if(A[i]>=0) pos.push_back(A[i]);
			else neg.push_back(A[i]);
		}

		if(K<=neg.size()){
			std::sort(neg.begin(), neg.end());
			for (size_t i = 0; i < neg.size(); ++i) {
				if(i<K) sum -= neg[i];
				else sum += neg[i];
			}
			for (size_t i = 0; i < pos.size(); ++i) {
				sum += pos[i];
			}
		}
		else{
			int min_val;
			bool is_first_found = false;
			for (size_t i = 0; i < neg.size(); ++i) {
				neg[i] *= -1;
				sum += neg[i];
				if(!is_first_found){
					min_val = neg[i];
					is_first_found = true;
				}
				else if(neg[i]<min_val) min_val = neg[i];
			}
			for (size_t i = 0; i < pos.size(); ++i) {
				sum += pos[i];
				if(!is_first_found){
					min_val = pos[i];
					is_first_found = true;
				}
				else if(pos[i]<min_val) min_val = pos[i];
			}
			if((K-neg.size())%2){
				sum -= 2*min_val;
			}
		}

		return sum;
    }
};
