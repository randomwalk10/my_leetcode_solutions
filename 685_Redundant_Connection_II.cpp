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
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
private:
	bool couldNodeBeRoot(int node, unordered_map<int, unordered_set<int>>& children, int len){
		// bfs
		unordered_set<int> visited;
		queue<int> q;
		q.push(node);
		visited.insert(node);
		while(!q.empty()){
			//get new node
			int new_node = q.front();
			q.pop();
			//add children of the new node
			if(children.end()!=children.find(new_node)){
				for(unordered_set<int>::iterator iter = children[new_node].begin(); \
						iter != children[new_node].end(); ++iter){
					if(visited.end()==visited.find(*iter)){
						q.push(*iter);
						visited.insert(*iter);
					}
				}
			}
		}
		// return
		return (int)visited.size() == len;
	}
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		unordered_map<int, vector<int>> parents;
		unordered_map<int, unordered_set<int>> children;
		int len = edges.size();
		// iterate through edges
		for(int i=0; i<len; ++i){
			parents[edges[i][1]].push_back(edges[i][0]);
			children[edges[i][0]].insert(edges[i][1]);
		}
		// case that there is a node with two parents
		// remove one of the two edges
		if((int)parents.size()<len){
			// find root node and the two edges
			int root;
			vector<vector<int>> candidates;
			for(int i=1; i<=len; ++i){
				unordered_map<int, vector<int>>::iterator iter = parents.find(i);
				if(parents.end()==iter){
					root = i;
				}
				else if(iter->second.size()==2){
					candidates.push_back( {iter->second[0], i} );
					candidates.push_back( {iter->second[1], i} );
				}
			}
			// remove one that is redundant
			for(int i=1; i>=0; --i){
				unordered_map<int, unordered_set<int>>::iterator iter = children.find(candidates[i][0]);
				iter->second.erase( iter->second.find(candidates[i][1]) );
				if(couldNodeBeRoot(root, children, len))
					return candidates[i];
				iter->second.insert( candidates[i][1] );
			}
		}
		// case that every node has exactly one parent
		// find the node that could be root and remove the edge with this node as child
		vector<int> res;
		for(int i=len-1; i>=0; --i){
			// check if node edges[i][1] could be the root
			if(couldNodeBeRoot(edges[i][1], children, len)){
				res = edges[i];
				break;
			}
		}
		// return the redundant edge
		return res;
    }
};
