/*
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].
*/
#include <string>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
		if(num==0) return "0";
		string out;
		bool isNeg = (num<0) ? true : false;
		num = abs(num);
		while(num){
			out.insert(out.begin(), '0'+num%7);
			num /= 7;
		}
		if(isNeg) out.insert(out.begin(), '-');
		return out;
    }
};
