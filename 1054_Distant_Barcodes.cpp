/*
In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

 

Example 1:

Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
Example 2:

Input: barcodes = [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,1,2,1,2]
 

Constraints:

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distant-barcodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct Compare{
	bool operator() (pair<int, int>& lhs, pair<int, int>& rhs){
		return lhs.first<rhs.first; // first counts, second value
	}
};

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
		unordered_map<int, int> m;
		vector<int> res;

		for (int i = 0; i < barcodes.size(); ++i) {
			++m[barcodes[i]];
		}

		for (auto iter = m.begin(); iter != m.end(); ++iter){
			q.push({iter->second, iter->first});
		}

		while(q.empty()==false){
			if((res.size()>0)&&(res.back()==q.top().second)){
				pair<int, int> tmp1 = q.top(); q.pop();
				pair<int, int> tmp2 = q.top(); q.pop();
				res.push_back(tmp2.second); --tmp2.first;
				q.push(tmp1);
				if(tmp2.first>0) q.push(tmp2);
			}
			else{
				pair<int, int> tmp = q.top(); q.pop();
				res.push_back(tmp.second); --tmp.first;
				if(tmp.first>0) q.push(tmp); 
			}
		}

		return res;
    }
};
