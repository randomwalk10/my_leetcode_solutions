/*
In a string S of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".

Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.

The final answer should be in lexicographic order.

 

Example 1:

Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
Example 2:

Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.
Example 3:

Input: "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
 

Note:  1 <= S.length <= 1000
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
		vector<vector<int>> out;
		int idx_i=0, idx_j=0;

		for(; idx_j<(int)S.size(); idx_j++){
			if(S[idx_i]!=S[idx_j]){
				if((idx_j-idx_i)>2){
					out.push_back({idx_i, idx_j-1});
				}
				idx_i = idx_j;
			}
		}

		if((idx_j-idx_i)>2){
			out.push_back({idx_i, idx_j-1});
		}

		return out;
    }
};
