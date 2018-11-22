/*
For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1 :

Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3 

Output: [1]
Example 2 :

Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5 

Output: [3, 4]
Note:

According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		if(n<1) return vector<int>();
		unordered_set<int> remain_nodes;
		vector<unordered_set<int>> links(n, unordered_set<int>());

		//trasverse edges
		for(int i=0; i<(int)edges.size(); ++i){
			links[edges[i].first].insert(edges[i].second);
			links[edges[i].second].insert(edges[i].first);
		}

		//get set of leaf nodes and remain nodes
		unordered_set<int> leaf_nodes;
		for(int i=0; i<n; ++i){
			remain_nodes.insert(i);
			if(links[i].size()==1) leaf_nodes.insert(i);
		}
		
		//trim leaf nodes
		while(remain_nodes.size()>2){
			unordered_set<int> new_leaf_nodes;
			//remove leaf nodes from remain nodes
			for(unordered_set<int>::iterator iter=leaf_nodes.begin();
					iter!=leaf_nodes.end(); ++iter){
				//update the new node that leaf node is connected to
				int new_node = *links[*iter].begin();
				links[new_node].erase(*iter);
				if(links[new_node].size()==1)
					new_leaf_nodes.insert(new_node);
				//update remain nodes
				remain_nodes.erase(*iter);
			}
			//update leaf nodes
			leaf_nodes = new_leaf_nodes;
		}

		//return
		vector<int> res;
		if(remain_nodes.size()==2){
			unordered_set<int>::iterator iter = remain_nodes.begin();
			int res1 = *iter;
			int res2 = *(++iter);
			if(res1>=res2) swap(res1, res2);
			res.push_back(res1);
			res.push_back(res2);
		}
		else{
			res.push_back(*remain_nodes.begin());
		}
		return res;
    }
};
