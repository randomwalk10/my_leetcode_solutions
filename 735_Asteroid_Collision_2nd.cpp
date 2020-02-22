/* O(N) in time and O(N) in space */
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> s;

        for(int i=0; i<(int)asteroids.size(); ++i){
            if(asteroids[i]>0){
                s.push(asteroids[i]);
            }
            else{
                bool to_keep = true;
                while(!s.empty()){
                    if(s.top()>(-asteroids[i])){
                        to_keep = false;
                        break;
                    }
                    else if(s.top()==(-asteroids[i])){
                        to_keep = false;
                        s.pop();
                        break;
                    }
                    else{
                        s.pop();
                    }
                }
                if(to_keep) res.push_back(asteroids[i]);
            }
        }

        stack<int> l;
        while(!s.empty()){
            l.push(s.top()); s.pop();
        }
        while(!l.empty()){
            res.push_back(l.top()); l.pop();
        }

        return res;
    }
};
