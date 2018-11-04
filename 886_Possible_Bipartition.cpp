/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].
*/
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		vector<vector<int>> graph(N+1, vector<int>());
		vector<bool> visited(N+1, false);
		unordered_set<int> remain;
		queue<int> q;
		vector<int> flags(N+1, -1);//0: group 0; 1: group 1; -1: not determined

		for(int i=0; i<(int)dislikes.size(); ++i){
			graph[dislikes[i][0]].push_back(dislikes[i][1]);
			graph[dislikes[i][1]].push_back(dislikes[i][0]);
			remain.insert(dislikes[i][0]);
			remain.insert(dislikes[i][1]);
		}

		while(!remain.empty()){
			q.push(*(remain.begin()));
			//depth first search
			while(!q.empty()){
				//get new node
				int new_node = q.front();
				q.pop();
				if(visited[new_node]) continue;
				visited[new_node] = true;
				remain.erase(new_node);
				//init flags at new_node for the very beginning
				if(flags[new_node]<0) flags[new_node] = 0;
				//add new edges to stack
				for(int i=0; i<(int)graph[new_node].size(); ++i){
					int next_node = graph[new_node][i];

					//flag checking
					if(flags[next_node]<0) flags[next_node] = 1 - flags[new_node];
					else if(flags[next_node]==flags[new_node]) return false;

					if(!visited[next_node])
						q.push(next_node);
				}
			}
		}

		return true;
    }
};
