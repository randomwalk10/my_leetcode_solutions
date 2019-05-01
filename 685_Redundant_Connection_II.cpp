/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:

Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
Example 2:

Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
Note:

The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
*/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
	int getRoot(int cur_node, vector<int>& parents, unordered_set<int>& visited){
		if(visited.end()!=visited.find(cur_node)) return cur_node;
		visited.insert(cur_node);
		if(cur_node!=parents[cur_node]){
			return getRoot(parents[cur_node], parents, visited);
		}
		return cur_node;
	}
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		int len = edges.size();
		vector<int> parents(len+1, 0);
		unordered_set<int> visited;
		// iterate through edges
		vector<int> candidate_a, candidate_b;
		for(int i=0; i<len; ++i){
			if(parents[edges[i][1]]>0){ // node edges[i][1] has two parents
				candidate_a = {parents[edges[i][1]], edges[i][1]};
				candidate_b = edges[i];
			}
			else{
				parents[edges[i][1]] = edges[i][0];
			}
		}
		// case that there is a node with two parents
		// remove one of the two edges
		if(!candidate_a.empty()){
			// detect if node candidate_a[1] is in a cycle
			// if yes, return candidate_a
			// otherwise, return candidate_b
			visited.insert(candidate_a[1]);
			if(getRoot(candidate_a[0], parents, visited)==candidate_a[1])
				return candidate_a;
			return candidate_b;
		}
		// case that every node has exactly one parent
		// find the node that is in a cycle
		vector<int> res;
		for(int i=len-1; i>=0; --i){
			// check if node edges[i][1] is in a cycle or not
			visited.clear();
			visited.insert(edges[i][1]);
			parents[edges[i][1]] = getRoot(edges[i][0], parents, visited);
			if(edges[i][1]==parents[edges[i][1]]){
				res = edges[i];
				break;
			}
		}
		// return the redundant edge
		return res;
    }
};
