/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(n) in time and O(n) in space */

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       stack<int> s;
       int res = 0;
       for(int i=0; i<(int)heights.size(); ++i){
            while( (!s.empty())&&(heights[s.top()]>=heights[i]) ){
                int k = s.top(); s.pop();
                int j;
                if(s.empty()) j = -1;
                else j = s.top();
                res = max(res, heights[k]*(i-j-1));
            }
            s.push(i);
       }
        while(!s.empty()){
            int i = s.top();
            s.pop();
            int j;
            if(s.empty()) j = -1;
            else j = s.top();
            res = max(res, heights[i]*((int)heights.size()-j-1));
        }
        return res;
    }
};
