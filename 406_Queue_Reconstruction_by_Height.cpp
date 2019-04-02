/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

#include <vector>
#include <algorithm>
using namespace std;

bool myFunction(pair<int, int> a, pair<int, int> b){
	if(a.first > b.first) return true;
	else if(a.first < b.first) return false;
	else if(a.second < b.second) return true;
	return false;
}

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		vector<pair<int, int>> res;
		if(people.empty()) return res;
		//sort people in descending order by h and ascending order by k
		std::sort(people.begin(), people.end(), myFunction);

		//insert people into res
		for(vector<pair<int, int>>::iterator iter = people.begin(); \
				iter != people.end(); ++iter){
			res.insert(res.begin()+iter->second, *iter);
		}

		//return
		return res;
    }
};
