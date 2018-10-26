/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		string out;
		int i=0;
		int carry=0;

		while( (i<(int)a.length()) || \
				(i<(int)b.length()) || \
				(carry!=0) ){
			//insert a new bit to the front of out string
			int temp = 0;
			if(i<(int)a.length()) temp += (a[(int)a.length()-1-i]=='1') ? 1 : 0;
			if(i<(int)b.length()) temp += (b[(int)b.length()-1-i]=='1') ? 1 : 0;
			temp += carry;
			out.insert(out.begin(), (temp%2) ? '1' : '0');

			//update index and carry
			i++;
			carry = temp / 2;
		}

		return out;
    }
};
