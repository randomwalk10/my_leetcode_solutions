/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Compare{
	public:
		bool operator() (pair<string,int>& lhs, pair<string, int>& rhs){
			if(lhs.second>rhs.second) return true;
			else if(lhs.second<rhs.second) return false;
			return lhs.first<rhs.first;
		}
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string> res(k, "");
		std::priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> q;
		unordered_map<string, int> m;

		for(auto w:words){
			m[w] += 1;
		}

		for(auto iter = m.begin(); iter != m.end(); ++iter){
			q.push(make_pair(iter->first, iter->second));
			if(q.size()>k) q.pop();
		}

		while(q.size()>0){
			res[q.size()-1] = q.top().first;
			q.pop();
		}

		return res;
    }
};
