/* O(n) in time and O(n) in space */
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int max_r = 0;
        int res = 0;

        for(int i=0; i<(int)height.size(); ++i){
            if( (s.empty())||(height[i]>height[s.top()]) ){
                s.push(i);
            }
        }

        for(int i=(int)height.size()-1; i>=0; --i){
            while(s.top()>i){
                s.pop();
            }
            max_r = max(max_r, height[i]);
            res += min(height[s.top()], max_r) - height[i];
        }

        return res;
    }
};
