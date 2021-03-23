/*
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorganize-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare_cnts(pair<char, int>& lhs, pair<char, int>& rhs){
	return lhs.second>rhs.second;
}

class Solution {
public:
    string reorganizeString(string S) {
		string res;
		vector<pair<char, int>> cnts;

		for (int i = 0; i < 26; ++i) {
			cnts.push_back(pair<char, int>('a'+i, 0));
		}
		for (int i = 0; i < S.size(); ++i) {
			++cnts[S[i]-'a'].second;
		}
		do {
			sort(cnts.begin(), cnts.end(), compare_cnts);
			if(cnts.begin()->second==0) break;
			if(res.empty()||(res.back()!=cnts.begin()->first)){
				res.push_back(cnts.begin()->first);
				--cnts.begin()->second;
			}
			else if(cnts[1].second==0) return "";
			else{
				res.push_back(cnts[1].first);
				--cnts[1].second;
			}
		} while (true);

		return res;
    }
};
