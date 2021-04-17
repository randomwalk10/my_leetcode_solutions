/*
Given a string s, sort it in decreasing order based on the frequency of characters, and return the sorted string.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of English letters and digits.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-characters-by-frequency
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <unordered_map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Compare
{
	public:
		bool operator() (pair<int, int>& lhs, pair<int,int>& rhs){
			return lhs.second<rhs.second;
		}
};

class Solution {
public:
    string frequencySort(string s) {
		string res;
		unordered_map<int, int> m;
		std::priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
		for (int i = 0; i < s.size(); ++i) {
			++m[(int)s[i]];
		}
		for(auto iter = m.begin(); iter != m.end(); ++iter){
			q.push({iter->first, iter->second});
		}
		while(q.empty()!=true){
			for (int i = 0; i < q.top().second; ++i) {
				res.push_back((char)q.top().first);
			}
			q.pop();
		}
		return res;
    }
};
