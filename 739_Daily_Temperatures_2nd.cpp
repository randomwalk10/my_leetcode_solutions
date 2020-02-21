/* O(N) in time and O(N) in space */
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s, l;
        vector<int> res(T.size(), 0);

        for(int i=0; i<(int)T.size(); ++i){
            while( (!s.empty())&&(s.top()<T[i]) ){
                res[l.top()] = i - l.top();
                s.pop(); l.pop();
            }
            s.push(T[i]);
            l.push(i);
        }

        return res;
    }
};
