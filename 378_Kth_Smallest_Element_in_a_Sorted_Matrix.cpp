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

		// breadth first search with priority queue
		q.push( Element(0, 0, matrix[0][0]) );
		is_visited[0][0] = true;
		while(cnt<k){
			// get new element from q
			Element new_node = q.top();
			q.pop();

			// add next elements to q
			res = new_node.val_;
			int cur_r = new_node.r_;
			int cur_c = new_node.c_;
			if( ( cur_r < rows - 1 ) && \
					(!is_visited[cur_r+1][cur_c]) ){
				q.push( Element(cur_r+1, cur_c, matrix[cur_r+1][cur_c]) ); 
				is_visited[cur_r+1][cur_c] = true;
			}
			if( ( cur_c < cols - 1 ) && \
					(!is_visited[cur_r][cur_c+1]) ){
				q.push( Element(cur_r, cur_c+1, matrix[cur_r][cur_c+1]) ); 
				is_visited[cur_r][cur_c+1] = true;
			}

			// update cnt
			++cnt;
		}


		// return
		return res;
    }
};
