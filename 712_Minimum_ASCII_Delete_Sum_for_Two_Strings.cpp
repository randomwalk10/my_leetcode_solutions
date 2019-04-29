/*
Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
Note:

0 < s1.length, s2.length <= 1000.
All elements of each string will have an ASCII value in [97, 122].
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
		int len1 = s1.size();
		int len2 = s2.size();
		vector<vector<int>> minSums(len1+1, vector<int>(len2+1, 0)); // minSums[i][j] is the minimum delete sum of substrings s1[i:] and s2[j:]

		// fill the borders of minSums
		for(int i=len1-1; i>=0; --i){
			minSums[i][len2] = minSums[i+1][len2] + s1[i];
		}
		for(int j=len2-1; j>=0; --j){
			minSums[len1][j] = minSums[len1][j+1] + s2[j];
		}

		// dynamic programming
		for(int i=len1-1; i>=0; --i){
			for(int j=len2-1; j>=0; --j){
				minSums[i][j] = min(minSums[i][j+1]+s2[j], minSums[i+1][j]+s1[i]);
				if(s1[i]==s2[j]){
					minSums[i][j] = min(minSums[i][j], minSums[i+1][j+1]);
				}
			}
		}

		// return
		return minSums[0][0];
    }
};
