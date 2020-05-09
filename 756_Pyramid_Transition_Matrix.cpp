/*
We are stacking blocks to form a pyramid. Each block has a color which is a one letter string.

We are allowed to place any color block C on top of two adjacent blocks of colors A and B, if and only if ABC is an allowed triple.

We start with a bottom row of bottom, represented as a single string. We also start with a list of allowed triples allowed. Each allowed triple is represented as a string of length 3.

Return true if we can build the pyramid all the way to the top, otherwise false.

Example 1:

Input: bottom = "BCD", allowed = ["BCG", "CDE", "GEA", "FFF"]
Output: true
Explanation:
We can stack the pyramid like this:
    A
   / \
  G   E
 / \ / \
B   C   D

We are allowed to place G on top of B and C because BCG is an allowed triple.  Similarly, we can place E on top of C and D, then A on top of G and E.
 

Example 2:

Input: bottom = "AABA", allowed = ["AAA", "AAB", "ABA", "ABB", "BAC"]
Output: false
Explanation:
We can't stack the pyramid to the top.
Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
 

Note:

bottom will be a string with length in range [2, 8].
allowed will have length in range [0, 200].
Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pyramid-transition-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(M^(N^2)) in time and O(N^2) in space, where M is the size of allowed and N is the length of bottom*/

#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    bool pyramidTransition(string& bottom, int idx, vector<vector<vector<int>>>& count, string& next_layer){
        string temp_bottom, temp_next_layer;
        if(idx>=((int)bottom.size()-1)){
            if(next_layer.size()==1) return true;
            temp_bottom = bottom;
            temp_next_layer = next_layer;
            bottom = next_layer;
            next_layer.clear();
            idx = 0;
        }
        bool res = false;
        for(int i=0; i<7; ++i){
            if(count[bottom[idx]-'A'][bottom[idx+1]-'A'][i]){
                next_layer.push_back(i+'A');
                res = pyramidTransition(bottom, idx+1, count, next_layer);
                next_layer.pop_back();
                if(res) break;
            }
        }
        if(temp_bottom.empty()==false){
            bottom = temp_bottom;
            next_layer = temp_next_layer;
        }
        return res;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<vector<vector<int>>> count(7, vector<vector<int>>(7, vector<int>(7, 0)));
        string next_layer;
        for(int i=0; i<(int)allowed.size(); ++i){
            count[allowed[i][0]-'A'][allowed[i][1]-'A'][allowed[i][2]-'A'] = 1;
        }
        return pyramidTransition(bottom, 0, count, next_layer);
    }
};
