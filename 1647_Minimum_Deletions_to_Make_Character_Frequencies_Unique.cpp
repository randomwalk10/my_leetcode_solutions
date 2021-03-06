/*
A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

 

Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.
Example 2:

Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
Example 3:

Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
 

Constraints:

1 <= s.length <= 105
s contains only lowercase English letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-deletions-to-make-character-frequencies-unique
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26, 0);
        unordered_set<int> freq;
        int res = 0;
        for(auto c:s){
            ++cnt[c-'a'];
        }

        for(auto f: cnt){
            if(f>0){
                while(freq.find(f)!=freq.end()){
                    --f;
                    ++res;
                }
                if(f>0) freq.insert(f);
            }
        }

        return res;
    }
};