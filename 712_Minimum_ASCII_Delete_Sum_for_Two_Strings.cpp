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
		// this is an improved version from one where minSums is of 2d
		int len1 = s1.size();
		int len2 = s2.size();
		vector<int> minSums(len2+1, 0); // minSums[j] is the minimum delete sums of a substring of s1 and s2[j:]

		// initialize minSums with the minimul delete sums of empty string and s2[j:]
		for(int j=len2-1; j>=0; --j){
			minSums[j] = minSums[j+1] + s2[j];
		}

		// dynamic programming
		for(int i=len1-1; i>=0; --i){
			int temp = minSums[len2];
			minSums[len2] += s1[i];
			for(int j=len2-1; j>=0; --j){
				// store the old minSums[j]
				int temp2 = minSums[j];
				// update minSums[j]
				minSums[j] = min(minSums[j+1]+s2[j], minSums[j]+s1[i]);
				if(s1[i]==s2[j]){
					minSums[j] = min(minSums[j], temp);
				}
				// update temp
				temp = temp2;
			}
		}

		// return
		return minSums[0];
    }
};
