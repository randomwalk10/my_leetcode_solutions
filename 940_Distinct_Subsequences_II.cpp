/*
Given a string S, count the number of distinct, non-empty subsequences of S .

Since the result may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
Example 2:

Input: "aba"
Output: 6
Explanation: The 6 distinct subsequences are "a", "b", "ab", "ba", "aa" and "aba".
Example 3:

Input: "aaa"
Output: 3
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
 

 

Note:

S contains only lowercase letters.
1 <= S.length <= 2000
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	const int mod = 1000000000 + 7;
	long long sum(vector<int>& ends){
		long long res = 0;
		for(int i=0; i<(int)ends.size(); ++i){
			res += ends[i];
		}
		return res;
	}
public:
    int distinctSubseqII(string S) {
		vector<int> ends(26, 0); // counts of subseq ending at each letter
		// dynamic programming
		for(int i=0; i<(int)S.size(); ++i){
			ends[S[i]-'a'] = (1 + sum(ends)) % mod; // this could be explained by theory of set
		}
		// return the sum of ends
		return sum(ends) % mod;
    }
};
