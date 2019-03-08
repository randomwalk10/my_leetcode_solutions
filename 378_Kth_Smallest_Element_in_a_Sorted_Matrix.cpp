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
#include <queue>
using namespace std;

class Element{
public:
	int r_;
	int c_;
	int val_;
	Element(): r_(0), c_(0), val_(0) {};
	Element(int r, int c, int val){
		r_ = r;
		c_ = c;
		val_ = val;
	};
};

struct hasLargerValue{
	bool operator () (const Element& lhs, const Element& rhs){
		return lhs.val_ > rhs.val_;
	};
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
		int cnt = 0;
		int res = 0;
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));
		std::priority_queue<Element, std::vector<Element>, hasLargerValue> q;

		// feed the first elment in each row into q
		// time complexity O( rows * log(rows) )
		for(int r=0; r<rows; ++r){
			q.push( Element(r, 0, matrix[r][0]) );
		}

		// find the kth smallest
		// time complexity k *( O(1) + O(rows) ) about O(rows^2*log(rows))
		while(cnt<k){
			// find the next smallest element
			Element new_node = q.top();
			q.pop();
			res = new_node.val_;

			// feed the next candidate into q
			int r = new_node.r_;
			int c = new_node.c_;
			if( c < cols - 1 ) q.push( Element(r, c+1, matrix[r][c+1]) ); 

			// update cnt
			++cnt;
		}

		// return
		return res;
    }
};
