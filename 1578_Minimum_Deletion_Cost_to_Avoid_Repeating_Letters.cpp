/*
Given a string s and an array of integers cost where cost[i] is the cost of deleting the ith character in s.

Return the minimum cost of deletions such that there are no two identical letters next to each other.

Notice that you will delete the chosen characters at the same time, in other words, after deleting a character, the costs of deleting other characters will not change.

 

Example 1:

Input: s = "abaac", cost = [1,2,3,4,5]
Output: 3
Explanation: Delete the letter "a" with cost 3 to get "abac" (String without two identical letters next to each other).
Example 2:

Input: s = "abc", cost = [1,2,3]
Output: 0
Explanation: You don't need to delete any character because there are no identical letters next to each other.
Example 3:

Input: s = "aabaa", cost = [1,2,3,4,1]
Output: 2
Explanation: Delete the first and the last character, getting the string ("aba").
 

Constraints:

s.length == cost.length
1 <= s.length, cost.length <= 10^5
1 <= cost[i] <= 10^4
s contains only lowercase English letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-deletion-cost-to-avoid-repeating-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
		int res = 0;
		int i = 0;
		while(i<(int)cost.size()){
			char base = s[i];
			int temp_sum = cost[i];
			int temp_max = cost[i];
			int j = i+1;
			while(j<(int)cost.size()){
				if(s[j]!=s[i]) break;
				temp_sum += cost[j];
				temp_max = (cost[j]>temp_max)?cost[j]:temp_max;
				++j;
			}
			res += temp_sum - temp_max;
			i = j;
		}
		return res;
    }
};
