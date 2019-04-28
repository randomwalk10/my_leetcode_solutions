/*
You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

Example 1:

Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Note:

The given list may contain duplicates, so ascending order means >= here.
1 <= k <= 3500
-105 <= value of elements <= 105.
For Java users, please note that the input type has been changed to List<List<Integer>>. And after you reset the code template, you'll see this point.
*/
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class myCompare{
	public:
		myCompare(){}
		bool operator () (pair<int, int>&a, pair<int, int>& b){
			return a.first > b.first;
		}
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
		int min_range = INT_MAX; // the minimal length of range
		int max_val = INT_MIN;
		vector<int> res; // the smallest range
		std::priority_queue<pair<int, int>, vector<pair<int, int>>, myCompare> q; // pair's first value is the value to rank, second value indicates the index of lists
		std::vector<int> lowest_idx(nums.size(), 0); // selected idx from each list

		// fill in q
		for(int i=0; i<(int)lowest_idx.size(); ++i){
			q.push(std::pair<int, int>(nums[i][lowest_idx[i]], i));
			max_val = max(max_val, nums[i][lowest_idx[i]]);
		}

		// pop the smallest item in q and replace with the next item in the same list in nums, until any list is completed
		while(true){
			// update res
			pair<int, int> cur_item = q.top();
			if(max_val-cur_item.first<min_range){
				res = {cur_item.first, max_val};
				min_range = max_val - cur_item.first;
			}
			
			// pop q
			q.pop();

			// get the next item or break out of the loop
			int idx = cur_item.second;
			++lowest_idx[idx];
			if(lowest_idx[idx]>=(int)nums[idx].size()){
				break;
			}
			q.push(std::pair<int, int>(nums[idx][lowest_idx[idx]], idx));

			// update max_val
			max_val = max(nums[idx][lowest_idx[idx]], max_val);
		}

		// return
		return res;
    }
};
