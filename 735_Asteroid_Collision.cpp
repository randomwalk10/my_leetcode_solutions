/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:

Input: 
asteroids = [5, 10, -5]
Output: [5, 10]
Explanation: 
The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.
Example 2:

Input: 
asteroids = [8, -8]
Output: []
Explanation: 
The 8 and -8 collide exploding each other.
Example 3:

Input: 
asteroids = [10, 2, -5]
Output: [10]
Explanation: 
The 2 and -5 collide resulting in -5.  The 10 and -5 collide resulting in 10.
Example 4:

Input: 
asteroids = [-2, -1, 1, 2]
Output: [-2, -1, 1, 2]
Explanation: 
The -2 and -1 are moving left, while the 1 and 2 are moving right.
Asteroids moving the same direction never meet, so no asteroids will meet each other.
Note:

The length of asteroids will be at most 10000.
Each asteroid will be a non-zero integer in the range [-1000, 1000]..
*/
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
	void goForward(vector<int>& asteroids, int& idx, \
			stack<int>& sl, stack<int>& sr, vector<bool>& isAvailable){
		if(sr.empty()){
			sl.push(idx);
			idx=-1;
		}
		else{
			int next_idx = sr.top();
			sr.pop();
			if(asteroids[next_idx]>0){
				sl.push(idx);
				idx = next_idx;
			}
			else if(asteroids[next_idx]+asteroids[idx]==0){
				isAvailable[idx] = false;
				isAvailable[next_idx] = false;
				idx = -1;
			}
			else if(asteroids[next_idx]+asteroids[idx]<0){
				isAvailable[idx] = false;
				idx = next_idx;
			}
			else{
				isAvailable[next_idx] = false;
			}
		}
	}
	void goBackward(vector<int>& asteroids, int& idx, \
			stack<int>& sl, vector<bool>& isAvailable){
		if(sl.empty()){
			sl.push(idx);
			idx=-1;
		}
		else{
			int next_idx = sl.top();
			if(asteroids[next_idx]<0){
				sl.push(idx);
				idx = -1;
			}
			else if(asteroids[next_idx]+asteroids[idx]==0){
				isAvailable[idx] = false;
				isAvailable[next_idx] = false;
				sl.pop();
				idx = -1;
			}
			else if(asteroids[next_idx]+asteroids[idx]<0){
				isAvailable[next_idx] = false;
				sl.pop();
			}
			else{
				isAvailable[idx] = false;
				idx = next_idx;
				sl.pop();
			}
		}
	}
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
		int n = asteroids.size();
		if(n<2) return asteroids;
		vector<bool> isAvailable(n, true);
		vector<int> res;
		stack<int> sl, sr;
		int idx = -1;

		//init sr
		for(int i=0; i<n; ++i){
			sr.push(n-1-i);
		}

		//fill in isAvailable
		while( (!sr.empty())||(idx>=0) ){
			if(idx<0){
				idx = sr.top();
				sr.pop();
			}
			else if(asteroids[idx]>0){
				goForward(asteroids, idx, sl, sr, isAvailable);
			}
			else{
				goBackward(asteroids, idx, sl, isAvailable);
			}
		}

		//generate res
		for(int i=0; i<n; ++i){
			if(isAvailable[i]) res.push_back(asteroids[i]);
		}

		return res;
    }
};
