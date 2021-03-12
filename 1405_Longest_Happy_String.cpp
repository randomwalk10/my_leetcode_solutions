/*
A string is called happy if it does not have any of the strings 'aaa', 'bbb' or 'ccc' as a substring.

Given three integers a, b and c, return any string s, which satisfies following conditions:

s is happy and longest possible.
s contains at most a occurrences of the letter 'a', at most b occurrences of the letter 'b' and at most c occurrences of the letter 'c'.
s will only contain 'a', 'b' and 'c' letters.
If there is no such string s return the empty string "".

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 2, b = 2, c = 1
Output: "aabbc"
Example 3:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It's the only correct answer in this case.
 

Constraints:

0 <= a, b, c <= 100
a + b + c > 0


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-happy-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare_abc(pair<int, int>& lhs, pair<int, int>& rhs){
	return (lhs.second>rhs.second)?true:false;
}

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
		vector<pair<int, int>> counts;
		string res;
		counts.push_back({'a', a});
		counts.push_back({'b', b});
		counts.push_back({'c', c});

		while(true){
			sort(counts.begin(), counts.end(), compare_abc);
			if((res.size()>=2)&&(res[res.size()-1]==counts[0].first)&&(res[res.size()-2]==counts[0].first)){
				if(counts[1].second==0) break;
				res.push_back(counts[1].first);
				--counts[1].second;
			}
			else if(counts[0].second==0) break;
			else{
				res.push_back(counts[0].first);
				--counts[0].second;
			}
		}

		return res;
    }
};
