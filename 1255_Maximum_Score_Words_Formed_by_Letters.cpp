/*
Given a list of words, list of  single letters (might be repeating) and score of every character.

Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.

 

Example 1:

Input: words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
Output: 23
Explanation:
Score  a=1, c=9, d=5, g=3, o=2
Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
Words "dad" and "dog" only get a score of 21.
Example 2:

Input: words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
Output: 27
Explanation:
Score  a=4, b=4, c=4, x=5, z=10
Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with a score of 27.
Word "xxxz" only get a score of 25.
Example 3:

Input: words = ["leetcode"], letters = ["l","e","t","c","o","d"], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
Output: 0
Explanation:
Letter "e" can only be used once.
 

Constraints:

1 <= words.length <= 14
1 <= words[i].length <= 15
1 <= letters.length <= 100
letters[i].length == 1
score.length == 26
0 <= score[i] <= 10
words[i], letters[i] contains only lower case English letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-score-words-formed-by-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(2^N) in time and O(N) in space, where N is the number of words */
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	int maxScoreWords(vector<string>& words, vector<int>& letters_cnt, vector<int>& score, \
			int temp_score, int idx){
		bool to_exit = true;
		for(int i=0; i<26; ++i){
			if(0>letters_cnt[i]){
				return -1;
			}
			else if(0<letters_cnt[i]){
				to_exit = false;
			}
		}
		if(to_exit) return temp_score;
		if(idx>=(int)words.size()) return temp_score;
		// skip words[idx]
		int temp_score1 = maxScoreWords(words, letters_cnt, score, temp_score, idx+1);
		temp_score1 = (temp_score1>temp_score)?temp_score1:temp_score;
		// use words[idx]
		int temp_add = 0;
		for(int i=0; i<(int)words[idx].size(); ++i){
			letters_cnt[words[idx][i]-'a'] -= 1;
			temp_add += score[words[idx][i]-'a'];
		}
		int temp_score2 = maxScoreWords(words, letters_cnt, score, temp_score+temp_add, idx+1);
		temp_score2 = (temp_score2>temp_score)?temp_score2:temp_score;
		for(int i=0; i<(int)words[idx].size(); ++i){
			letters_cnt[words[idx][i]-'a'] += 1;
		}
		return (temp_score1>temp_score2)?temp_score1:temp_score2;
	}
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
		vector<int> letters_cnt(26, 0);
		for(int i=0; i<(int)letters.size(); ++i){
			letters_cnt[letters[i]-'a'] += 1;
		}
		return maxScoreWords(words, letters_cnt, score, 0, 0);
    }
};
