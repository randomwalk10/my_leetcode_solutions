/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(NULL==node) return NULL;
		//init
		UndirectedGraphNode *out = new UndirectedGraphNode(node->label);
		queue<UndirectedGraphNode *> new_nodes;
		unordered_set<long long> visited;
		unordered_map<long long, long long> old_new_map;
		new_nodes.push(node);
		old_new_map[(long long) node] = (long long) out;
		//transverse graph vis BFS
		while(!new_nodes.empty()){
			//search neighbours
			UndirectedGraphNode* seed = new_nodes.front();
			new_nodes.pop();
			if(visited.end()!=visited.find((long long)seed)) continue;
			visited.insert((long long)seed);
			UndirectedGraphNode* clone = (UndirectedGraphNode *)old_new_map[(long long)seed];
			for(vector<UndirectedGraphNode *>::iterator iter = seed->neighbors.begin(); \
					iter != seed->neighbors.end(); ++iter){
				//clone neighbors if necessary and update connection of clone node
				UndirectedGraphNode *temp;
				if(old_new_map.end()==old_new_map.find((long long)*iter)){
					temp = new UndirectedGraphNode((*iter)->label);
					old_new_map[(long long)*iter] = (long long)temp;
				}
				else temp = (UndirectedGraphNode *) old_new_map[(long long)*iter];
				clone->neighbors.push_back(temp);
				//put *iter into new_nodes if it is not visited yet.
				if(visited.end()==visited.find((long long)*iter)) new_nodes.push(*iter);
			}
		}
		//return
		return out;
    }
};
