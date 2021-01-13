/*
We have a set of items: the i-th item has value values[i] and label labels[i].

Then, we choose a subset S of these items, such that:

|S| <= num_wanted
For every label L, the number of items in S with label L is <= use_limit.
Return the largest possible sum of the subset S.

 

Example 1:

Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, use_limit = 1
Output: 9
Explanation: The subset chosen is the first, third, and fifth item.
Example 2:

Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], num_wanted = 3, use_limit = 2
Output: 12
Explanation: The subset chosen is the first, second, and third item.
Example 3:

Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 1
Output: 16
Explanation: The subset chosen is the first and fourth item.
Example 4:

Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 2
Output: 24
Explanation: The subset chosen is the first, second, and fourth item.
 

Note:

1 <= values.length == labels.length <= 20000
0 <= values[i], labels[i] <= 20000
1 <= num_wanted, use_limit <= values.length
通过次数3,025提交次数5,773

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-values-from-labels
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int, int>> s;
        unordered_map<int, int> m;
        int cnt = 0;
        int res = 0;

        for (int i = 0; i < values.size(); ++i)
        {
            s.push_back({values[i], labels[i]});
            if(m.end()==m.find(labels[i])) m[labels[i]] = 0;
        }

        sort(s.begin(), s.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs){
            return (lhs.first==rhs.first)?lhs.second<rhs.second:lhs.first>rhs.first;
        });

        for(auto item: s){
            if(cnt==num_wanted) break;
            unordered_map<int, int>::iterator iter = m.find(item.second);
            if(iter->second<use_limit){
                res += item.first;
                ++iter->second;
                ++cnt;
            }
        }
        
        return res;
    }
};