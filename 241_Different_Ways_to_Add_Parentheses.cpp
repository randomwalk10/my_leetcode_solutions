/*
 *
 Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/

#include <stdlib.h>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
	vector<int> diffWaysToCompute(string& input, int start, int end, \
			unordered_map<string, vector<int>>& dp_map){
		vector<int> res;
		//fill in res
		for(int i=start; i<end; ++i){
			if( (input[i]=='+')||(input[i]=='-')||(input[i]=='*') ){
				//left
				string left_s = input.substr(start, i-start);
				vector<int> left_res;
				if(dp_map.end()==dp_map.find(left_s)){
					left_res = diffWaysToCompute(input, start, i, dp_map);
				}
				else{
					left_res = dp_map[left_s];
				}
				//right
				string right_s = input.substr(i+1, end-i-1);
				vector<int> right_res;
				if(dp_map.end()==dp_map.find(right_s)){
					right_res = diffWaysToCompute(input, i+1, end, dp_map);
				}
				else{
					right_res = dp_map[right_s];
				}
				//combine
				for(int l=0; l<(int)left_res.size(); ++l){
					for(int r=0; r<(int)right_res.size(); ++r){
						if(input[i]=='+')
							res.push_back(left_res[l]+right_res[r]);
						else if(input[i]=='-')
							res.push_back(left_res[l]-right_res[r]);
						else
							res.push_back(left_res[l]*right_res[r]);
					}
				}
			}
		}
		if(res.empty()){//contains only number
			res.push_back(atoi(input.substr(start, end-start).c_str()));
		}
		//update dp map
		dp_map[input.substr(start, end-start)] = res;
		//return
		return res;
	}
public:
    vector<int> diffWaysToCompute(string input) {
		unordered_map<string, vector<int>> dp_map;
		return diffWaysToCompute(input, 0, input.size(), dp_map);
    }
};
