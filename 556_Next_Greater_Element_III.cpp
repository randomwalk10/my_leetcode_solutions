/*
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:

Input: 12
Output: 21
 

Example 2:

Input: 21
Output: -1
*/
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
		vector<int> digs;
		bool isFound = false;
		int out = -1;

		while(n){
			digs.push_back(n%10);
			n /= 10;
		}

		for(size_t i=1; i<digs.size(); ++i){
			for(size_t j=0; j<i; ++j){
				if(digs[i]<digs[j]){
					digs[i] ^= digs[j];
					digs[j] ^= digs[i];
					digs[i] ^= digs[j];
					isFound = true;
					break;
				}
			}
			if(isFound){
				std::sort(digs.begin(), digs.begin()+i, \
						std::greater<int>());
				break;
			}
		}

		if(isFound){
			out = 0;
			for(size_t i=0; i<digs.size(); ++i){
				int temp = out;
				out *= 10;
				out += digs[digs.size()-i-1];
				//detect integer overflow
				if( (out-digs[digs.size()-i-1])/10 != temp ) \
					return -1;
			}
		}

		return out;
    }
};
