/*
Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/
#include <vector>
#include <stack>
using namespace std;

/*solution 1
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> lut(71, -1);
		vector<int> out(temperatures.size());

		for(int i=(int)(temperatures.size()-1); i>=0; --i){
			out[i] = (-1==lut[temperatures[i]-30]) ? 0 : \
					 (lut[temperatures[i]-30]-i);
			for(int j=30; j<temperatures[i]; ++j){
				lut[j-30] = i;
			}
		}

		return out;
    }
};
*/

/*solution 2
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> out(temperatures.size(), 0);

		for(int i=(int)(temperatures.size()-2); i>=0; --i){
			int j = i+1;
			while(j<(int)temperatures.size()){
				if(temperatures[i]<temperatures[j]){
					out[i] = j - i;
					break;
				}
				else if(temperatures[i]==temperatures[j]){
					out[i] = (0==out[j]) ? 0 : out[j] + j - i;
					break;
				}
				else if(0==out[j]){
					out[i] = 0;
					break;
				}
				j += out[j];
			}
		}

		return out;
    }
};
*/

/* solution3 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> out(temperatures.size(), 0);
		stack<int> _stack;

		for(int i=0; i<(int)temperatures.size(); ++i){
			while( !_stack.empty() && temperatures[_stack.top()]<temperatures[i] ){
			   out[_stack.top()] = i - _stack.top();	
			   _stack.pop();
			}
			_stack.push(i);
		}

		return out;
    }
};
