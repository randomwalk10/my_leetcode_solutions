/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:

Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16 
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4 
Explanation: The two words can be "ab", "cd".
Example 3:

Input: ["a","aa","aaa","aaaa"]
Output: 0 
Explanation: No such pair of words.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-word-lengths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
		if(words.size()==0) return 0;
		int res = 0;
		vector<int> codes;

		for (int i = 0; i < (int)words.size(); ++i) {
			codes.push_back(0);
			for (int j = 0; j < (int)words[i].size(); ++j) {
				codes[i] |= (1<<(words[i][j]-'a'));
			}
		}

		for (int i = 0; i < (int)words.size(); ++i) {
			for (int j = i+1; j < (int)words.size(); ++j) {
				if( (codes[i]&codes[j])==0 ){
					int temp = words[i].size()*words[j].size();
					res = (temp>res) ? temp : res;
				}
			}
		}

		return res;
    }
};
