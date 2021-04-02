/*
An encoded string S is given.  To find and write the decoded string to a tape, the encoded string is read one character at a time and the following steps are taken:

If the character read is a letter, that letter is written onto the tape.
If the character read is a digit (say d), the entire current tape is repeatedly written d-1 more times in total.
Now for some encoded string S, and an index K, find and return the K-th letter (1 indexed) in the decoded string.

 

Example 1:

Input: S = "leet2code3", K = 10
Output: "o"
Explanation: 
The decoded string is "leetleetcodeleetleetcodeleetleetcode".
The 10th letter in the string is "o".
Example 2:

Input: S = "ha22", K = 5
Output: "h"
Explanation: 
The decoded string is "hahahaha".  The 5th letter is "h".
Example 3:

Input: S = "a2345678999999999999999", K = 1
Output: "a"
Explanation: 
The decoded string is "a" repeated 8301530446056247680 times.  The 1st letter is "a".
 

Constraints:

2 <= S.length <= 100
S will only contain lowercase letters and digits 2 through 9.
S starts with a letter.
1 <= K <= 10^9
It's guaranteed that K is less than or equal to the length of the decoded string.
The decoded string is guaranteed to have less than 2^63 letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decoded-string-at-index
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string decodeAtIndex(string S, int K) {
		string res;
		int cnt = 0;
		stack<vector<int>> s;
		for (int i = 0; i < S.size(); ++i) {
			if((S[i]>='a')&&(S[i]<='z')){
				++cnt;
				if(cnt==K){
					res = S[i];
					break;
				}
			}
			else{
				long long tmp = (long long)(S[i] - '0')*cnt;
				if(tmp>=(long long)K){
					int residual = K%cnt;
					if(residual==0) residual = cnt;
					while(s.empty()==false){
						int prev_i = s.top()[0];
						int prev_cnt = s.top()[1];
						if(residual>prev_cnt){
							break;
						}
						else{
							residual %= (prev_cnt/(S[prev_i]-'0'));
							if(residual==0) residual = prev_cnt/(S[prev_i]-'0');
							s.pop();
						}
					}
					if(s.empty()){
						res = S[residual-1];
					}
					else{
						res = S[residual-s.top()[1]+s.top()[0]];
					}
					break;
				}
				else{
					cnt = (int)tmp;
					s.push({i, cnt});
				}
			}
		}
		return res;
    }
};
