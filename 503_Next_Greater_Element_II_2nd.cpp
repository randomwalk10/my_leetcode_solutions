/* O(N) in time and O(N) in space */
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.empty()) return {};
        stack<int> s;
        vector<int> res(nums.size(), -1);

        for(int i=0; i<(int)nums.size()*2; ++i){
            int idx = i%nums.size();
            while( (!s.empty())&&(nums[s.top()]<nums[idx]) ){
                res[s.top()] = nums[idx];
                s.pop();
            }
            if(res[idx]==-1) s.push(idx);
        }

        return res;
    }
};
