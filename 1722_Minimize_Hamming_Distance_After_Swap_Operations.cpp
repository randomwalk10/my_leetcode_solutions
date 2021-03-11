/*
You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.

The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).

Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.

 

Example 1:

Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
Output: 1
Explanation: source can be transformed the following way:
- Swap indices 0 and 1: source = [2,1,3,4]
- Swap indices 2 and 3: source = [2,1,4,3]
The Hamming distance of source and target is 1 as they differ in 1 position: index 3.
Example 2:

Input: source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
Output: 2
Explanation: There are no allowed swaps.
The Hamming distance of source and target is 2 as they differ in 2 positions: index 1 and index 2.
Example 3:

Input: source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
Output: 0
 

Constraints:

n == source.length == target.length
1 <= n <= 105
1 <= source[i], target[i] <= 105
0 <= allowedSwaps.length <= 105
allowedSwaps[i].length == 2
0 <= ai, bi <= n - 1
ai != bi


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimize-hamming-distance-after-swap-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
	int find_parent(int x, vector<int>& parents){
		while(x!=parents[x]) x = parents[x];
		return x;
	}
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
		// construct disjointed set unit
		vector<int> parents(source.size(), 0);
		for (int i = 0; i < (int)parents.size(); ++i) {
			parents[i] = i;
		}
		for(auto x:allowedSwaps){
			int a = x[0];
			int b = x[1];
			int pa = find_parent(a, parents);
			int pb = find_parent(b, parents);
			if(pa!=pb){
				parents[pa] = min(pa, pb);
				parents[pb] = min(pa, pb);
			}
		}
		// construct val2idx
		unordered_map<int, unordered_set<int>> val2idx;
		for (int i = 0; i < (int)source.size(); ++i) {
			val2idx[source[i]].insert(i);
		}
		// perform swap
		int res = 0;
		for (int i = 0; i < (int)source.size(); ++i) {
			auto idx_iter = val2idx.find(target[i]);
			if(source[i]==target[i]){
				idx_iter->second.erase(idx_iter->second.find(i));
				if(idx_iter->second.empty()) val2idx.erase(idx_iter);
				continue;
			}
			else if(val2idx.end()==idx_iter){
				++res; continue;
			}
			++res;
			for(int idx:idx_iter->second){
				int pa = find_parent(i, parents);
				int pb = find_parent(idx, parents);
				if(pa!=pb) continue;
				// update val2idx
				idx_iter->second.erase(idx_iter->second.find(idx));
				if(idx_iter->second.empty()) val2idx.erase(idx_iter);
				auto i_iter = val2idx.find(source[i]);
				i_iter->second.erase(i_iter->second.find(i));
				i_iter->second.insert(idx);
				// swap
				source[i] ^= source[idx];
				source[idx] ^= source[i];
				source[i] ^= source[idx];
				--res;
				break;
			}
		}
		return res;
    }
};
