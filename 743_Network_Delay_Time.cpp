/*
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Note:

N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
*/

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

class mycomparison
{
public:
  bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const
  {
	  return lhs.second > rhs.second; // compare distance
  }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		if(N<2) return 0;
		unordered_map<int, vector<pair<int, int>>> node2edges;
		unordered_set<int> visited;
		std::priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> q;
		int res = 0;
		// fill in node2edges;
		for(int i=0; i<(int)times.size(); ++i){
			node2edges[times[i][0]].push_back(pair<int, int>(times[i][1], times[i][2]));
		}
		// bfs with shortest distance priority
		q.push(pair<int, int>(K, 0));
		while(!q.empty()){
			// get the next in queue
			pair<int, int> new_item = q.top();
			q.pop();
			// check if new_item is visited
			if(visited.end()!=visited.find(new_item.first)) continue;
			// update res and mark new_item as visited
			res = new_item.second;
			visited.insert(new_item.first);
			// search for its targets
			// add into queue if not visited
			if(node2edges.end()!=node2edges.find(new_item.first)){
				for(vector<pair<int, int>>::iterator iter=node2edges[new_item.first].begin(); \
						iter!=node2edges[new_item.first].end(); ++iter){
					if(visited.end()==visited.find(iter->first)){
						q.push(pair<int, int>(iter->first, iter->second+new_item.second));
					}
				}
			}
		}
		
		// return
		return ((int)visited.size()<N) ? -1 : res;
    }
};
