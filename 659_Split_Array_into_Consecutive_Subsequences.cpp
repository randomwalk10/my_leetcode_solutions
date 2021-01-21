/*
Given an array nums sorted in ascending order, return true if and only if you can split it into 1 or more subsequences such that each subsequence consists of consecutive integers and has length at least 3.

 

Example 1:

Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
Example 2:

Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
Example 3:

Input: [1,2,3,4,4,5]
Output: False
 

Constraints:

1 <= nums.length <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<int> total(3, 0); // cnt of sub seq with len 1, 2, 3 or more
        unordered_map<int, vector<int>> tails; // int n -> cnt of sub seq with len 1, 2, 3 or more

        for(int n: nums){
            if(tails.end()==tails.find(n-1)){
                if( (tails.end()==tails.find(n))&&(total[0]+total[1]>0) ) return false;
                else if(tails.end()==tails.find(n)) tails[n] = {1, 0, 0};
                else ++tails[n][0];
                ++total[0];
            }
            else{
                if(tails.end()==tails.find(n)) tails[n] = {0, 0, 0};

                if(tails[n-1][0]>0){
                    --tails[n-1][0];
                    ++tails[n][1];
                    --total[0];
                    ++total[1];
                }
                else if(tails[n-1][1]>0){
                    --tails[n-1][1];
                    ++tails[n][2];
                    --total[1];
                    ++total[2];
                }
                else{
                    --tails[n-1][2];
                    ++tails[n][2];
                }

                if(tails[n-1][0]+tails[n-1][1]+tails[n-1][2]==0) tails.erase(tails.find(n-1));
            }
        }

        return total[0]+total[1]==0;
    }
};