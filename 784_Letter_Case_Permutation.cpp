/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length between 1 and 12.
S will consist only of letters or digits.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-case-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    void letterCasePermutation(string& S, vector<string>& res, int idx, string& temp){
        if(idx>=(int)S.size()){
            res.push_back(temp);
            return;
        }
        bool spin = false;
        char spin_c;
        if( (S[idx]>='0')&&(S[idx]<='9') ){
            ;
        }
        else if( (S[idx]>='a')&&(S[idx]<='z') ){
            spin_c = S[idx] + 'A' - 'a';
            spin = true;
        }
        else{
            spin_c = S[idx] - 'A' + 'a';
            spin = true;
        }
        temp.push_back(S[idx]);
        letterCasePermutation(S, res, idx+1, temp);
        temp.pop_back();
        if(spin){
            temp.push_back(spin_c);
            letterCasePermutation(S, res, idx+1, temp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        string temp;
        letterCasePermutation(S, res, 0, temp);
        return res;
    }
};
