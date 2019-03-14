/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.
*/
#include <vector>
using namespace std;

class Solution {
private:
	int findNumberElementsLessOrEqualTo(vector<vector<int>>& matrix, int row, int limit){
		int lo = 0, hi = matrix[row].size() - 1;
		if(matrix[row][lo]>limit) return 0;
		else if(matrix[row][hi]<=limit) return matrix[row].size();
		// now matrix[row][lo] <= limit < matrix[row][hi]
		// do binary search until hi-lo==1
		while(hi-lo>1){
			int mid = (lo + hi) / 2;
			if(matrix[row][mid]<=limit) lo = mid;
			else hi = mid;
		}
		// return
		return lo + 1;
	}
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
		//init
		int rows = matrix.size();
		int cols = matrix[0].size();
		//lo: the val that is the less or equal to the kth smallest element
		//hi: the val that is greater or equal to the kth smallest element
		int lo = matrix[0][0], hi = matrix[rows-1][cols-1];
		//binary search
		while(lo<hi){
			int mid = (lo + hi) / 2;
			// find the number of elements <= mid
			int cnt = 0;
			for(int r = 0; r < rows; ++r){
				// find the number of elements <= mid in row r
				cnt += findNumberElementsLessOrEqualTo(matrix, r, mid);
				if(cnt>=k) break;
			}
			// if cnt < k, increase lo
			// if cnt >= k, decrease hi
			if(cnt < k) lo = mid + 1;
			else hi = mid;
		}
		//return
		return lo;
    }
};
