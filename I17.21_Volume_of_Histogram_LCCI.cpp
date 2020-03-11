/*
Imagine a histogram (bar graph). Design an algorithm to compute the volume of water it could hold if someone poured water across the top. You can assume that each histogram bar has width 1.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/volume-of-histogram-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(N) in time and O(N) in space */
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int res = 0;

        for(int i=0; i<(int)height.size(); ++i){
            if(s.empty()) s.push(height[i]);
            else s.push(max(s.top(), height[i]));
        }
        int max2right = INT_MIN;
        for(int i=(int)height.size()-1; i>=0; --i){
            max2right = max(max2right, height[i]);
            res += min(s.top(), max2right) - height[i];
            s.pop();
        }

        return res;
    }
};
