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
using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		vector<bool> left_group(N+1, false);
		vector<bool> right_group(N+1, false);
		vector<bool> placed_list(dislikes.size(), false);
		bool exitFlag = false;

		while(!exitFlag){
			left_group = vector<bool>(N+1, false);
			right_group = vector<bool>(N+1, false);

			int count = 0;
			int prev = 0;

			do{
				prev = count;
				for(int i=0; i<(int)dislikes.size(); ++i){
					if(placed_list[i]==false){
						int l = dislikes[i][0];
						int r = dislikes[i][1];

						if(count==0){
							left_group[l] = true;
							right_group[r] = true;
							count++;
							placed_list[i] = true;
						}
						else if( (left_group[l]&&left_group[r]) || \
								(right_group[l]&&right_group[r]) )
							return false;
						else if(left_group[l]||right_group[r]){
							left_group[l] = true;
							right_group[r] = true;
							count++;
							placed_list[i] = true;
						}
						else if(right_group[l]||left_group[r]){
							right_group[l] = true;
							left_group[r] = true;
							count++;
							placed_list[i] = true;
						}
					}
				}
			} while(count!=prev);

			if(0==count) exitFlag = true;
		}

		return true;
    }
};
