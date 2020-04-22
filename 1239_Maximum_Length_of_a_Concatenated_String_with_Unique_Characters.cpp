/*
Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

Return the maximum possible length of s.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lower case English letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int maxLength(vector<string>& arr, vector<int>& cnts, \
                    int idx, int bits, int res){
        if(idx>=(int)cnts.size()) return res;
        int temp1=0, temp2=0;
        if(bits&cnts[idx]) ;
        else if(cnts[idx]>0){
            temp1 = maxLength(arr, cnts, idx+1, \
                            bits|cnts[idx], res+arr[idx].size());
        }
        temp2 = maxLength(arr, cnts, idx+1, bits, res);
        return (temp1>temp2)?temp1:temp2;
    }
public:
    int maxLength(vector<string>& arr) {
        int res = 0;
        vector<int> cnts;
        for(int i=0; i<(int)arr.size(); ++i){
            int temp = 0;
            for(int j=0; j<(int)arr[i].size(); ++j){
                int mask = 1 << (arr[i][j]-'a');
                if(mask&temp){
                    temp = -1;
                    break;
                }
                temp |= mask;
            }
            cnts.push_back(temp);
        }
        res = maxLength(arr, cnts, 0, 0, 0);
        return res;
    }
};
