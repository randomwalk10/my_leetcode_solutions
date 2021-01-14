#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        int res = 1;

        sort(points.begin(), points.end(), [](const vector<int>& lhs, const vector<int>& rhs){
            return (lhs[1]==rhs[1])?lhs[0]<rhs[0]:lhs[1]<rhs[1];
        });

        int end = points[0][1];
        for(auto pt: points){
            if(pt[0]>end){
                ++res;
                end = pt[1];
            }
        }

        return res;
    }
};